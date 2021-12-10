#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<char, int> points;
    points[')'] = 1;
    points[']'] = 2;
    points['}'] = 3;
    points['>'] = 4;
    unordered_map<char, char> pairs;
    pairs['('] = ')';
    pairs['['] = ']';
    pairs['{'] = '}';
    pairs['<'] = '>';
    string line;
    char cur;
    ll curScore;
    bool corrupted;
    vector<ll> scores;
    while (getline(cin, line)) {
        stack<char> curStack;
        corrupted = false;
        for (auto &c : line) {
            if (pairs.find(c) != pairs.end()) {
                curStack.push(c);
            } else {
                if (curStack.empty()) {
                    break;
                }
                cur = curStack.top(); curStack.pop();
                if (pairs[cur] != c) {
                    corrupted = true;
                    break;
                }
            }
        }
        curScore = 0;
        while (!corrupted && !curStack.empty()) {
            cur = curStack.top(); curStack.pop();
            char close = pairs[cur];
            curScore *= 5;
            curScore += points[close];
        }
        if (curScore != 0) {
            scores.push_back(curScore);
        }
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size() / 2];
    return 0;
}