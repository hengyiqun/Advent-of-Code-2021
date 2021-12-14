#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line, cur;
    getline(cin, line);
    unordered_map<string, ll> count;
    for (int i = 0; i < line.size(); ++i) {
        if (i != line.size() - 1) {
            cur = line.substr(i, 2);
            count[cur]++;
        }
    }
    string two, insert;
    vector<pair<string, string>> inserts;
    while (getline(cin, cur)) {
        if (cur.find("->") != string::npos) {
            two = cur.substr(0, 2);
            insert = cur.back();
            inserts.push_back(make_pair(two, insert));
        }
    }
    
    ll curCount;
    for (int t = 0; t < 40; ++t) {
        unordered_map<string, ll> tempCount;
        for (auto &[two, insert] : inserts) {
            if (count.find(two) != count.end()) {
                curCount = count[two];
                count[two] = 0;
                tempCount[two[0] + insert] += curCount;
                tempCount[insert + two[1]] += curCount;
            }
        }

        for (auto &[k, v]: tempCount) {
            count[k] += v;
        } 
    }

    unordered_map<char, ll> alphabetCount;
    for (auto &[k, v]: count) {
        alphabetCount[k[0]] += v;
        alphabetCount[k[1]] += v;
        //cout << k[0] << ' ' << k[1] << ' ' << v << '\n';
    }
    ll maxCount = 0, minCount = 1e18;
    int numOdd = 0;
    for (auto &[k, v]: alphabetCount) {
        if (v % 2 == 1) {
            v /= 2;
            v++;
            numOdd++;
        } else {
            v /= 2;
        }
        maxCount = max(maxCount, v);
        minCount = min(minCount, v);
    }
    if (numOdd == 0) {      // line[0] == line.back()
        alphabetCount[line[0]]++;
        maxCount = 0, minCount = 1e18;
        for (auto &[k, v] : alphabetCount) {
            maxCount = max(maxCount, v);
            minCount = min(minCount, v);
        }
    }
    cout << maxCount - minCount;
    return 0;
}

/*
NBCCNBBBCBHCB
BH 1
CC 1
HC 1
BB 2
CN 1
CB 2
BC 2
NB 2

B 11 = 6
H 2 = 1
C 8 = 4
N 3 = 2
*/

/*
ABABC

AB
BA
AB
BC

A 3
B 4
C 1


ABBCA

AB
BB
BC
CA

A 2 = 1
B 4 = 2
C 2 = 1
*/