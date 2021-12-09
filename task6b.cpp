#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line; getline(cin, line);
    stringstream ss(line);
    vector<int> timers;
    for (int i; ss >> i;) {
        timers.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    unordered_map<ll, ll> count;
    for (int i = 1; i <= 7; ++i) {
        ll curDay, curNum, total = 0;
        map<ll, ll> fishes;
        fishes[i] = 1;
        while (fishes.begin()->first <= 256) {
            curDay = fishes.begin()->first;
            curNum = fishes.begin()->second;
            
            if (fishes.find(curDay + 9) != fishes.end()) {
                fishes[curDay + 9] += curNum;
            } else {
                fishes[curDay + 9] = curNum;
            }

            if (fishes.find(curDay + 7) != fishes.end()) {
                fishes[curDay + 7] += curNum;
            } else {
                fishes[curDay + 7] = curNum;
            }
            total += curNum;

            fishes.erase(fishes.begin());
        }
        count[i-1] = total;
    }
    ll totalFishes = timers.size();
    for (int i = 0; i < timers.size(); ++i) {
        totalFishes += count[timers[i]];
    }
    cout << totalFishes;
    return 0;
}