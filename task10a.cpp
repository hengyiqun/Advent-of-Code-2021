#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<char, int> scores;
    unordered_map<char, char> pairs;
    pairs[')'] = '(';
    pairs[']'] = '[';
    pairs['}'] = '{';
    pairs['>'] = '<';
    scores[')'] = 3;
    scores[']'] = 57;
    scores['}'] = 1197;
    scores['>'] = 25137;
    string line;
    int totalScore = 0;
    char cur;
    while (getline(cin, line)) {
        stack<char> curStack;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<') {
                curStack.push(line[i]);
            } else {
                if (curStack.empty()) {
                    totalScore += scores[line[i]];
                    break;
                }
                cur = curStack.top(); curStack.pop();
                if (pairs[line[i]] != cur) {
                    totalScore += scores[line[i]];
                    break;
                }   
            }
        }
    }
    cout << totalScore;
    return 0;
}
