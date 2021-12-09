#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line, digits;
    int count = 0;
    while (getline(cin, line)) {
        digits = line.substr(line.find("|") + 1);
        stringstream ss(digits);
        for (string cur; ss >> cur;) {
            if (cur.size() <= 4 || cur.size() == 7) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}