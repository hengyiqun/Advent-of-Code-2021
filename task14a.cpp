#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line;
    getline(cin, line);
    list<pair<char, bool>> polymer;
    for (int i = 0; i < line.size(); ++i) {
        polymer.push_back(make_pair(line[i], true));
    }
    char first, second, insert;
    vector<tuple<char, char, char>> inserts;
    while (getline(cin, line)) {
        if (line.find("->") != string::npos) {
            first = line[0];
            second = line[1];
            insert = line.back();
            inserts.push_back(make_tuple(first, second, insert));
            // cout << first << ' ' << second << ' ' << insert << '\n';
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (auto &[first, second, insert]: inserts) {
            for (auto it = polymer.begin(); it != polymer.end(); ++it) {
                if ((*it).first == first && (*it).second && (*next(it)).first == second && (*next(it)).second) {

                    // cout << (*it).first << ' ' << (*next(it)).first << ' ' << insert << '\n';
                    polymer.insert(next(it), make_pair(insert, false));
                }
            }
        }

        for (auto it = polymer.begin(); it != polymer.end(); ++it) {
            (*it).second = true;
            // cout << (*it).first;
        }
        // cout << '\n';
    }

    // cout << polymer.size() << '\n';

    unordered_map<char, int> count;
    int maxCount = 0, minCount = 1e9;
    for (auto &[c, b] : polymer) {
        count[c]++;
    }
    for (auto &[k, v] : count) {
        cout << k << ' ' << v << '\n';
        maxCount = max(maxCount, v);
        minCount = min(minCount, v);
    }
    cout << maxCount - minCount;
    return 0;
}