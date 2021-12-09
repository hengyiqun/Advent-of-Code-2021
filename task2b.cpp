#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll initialX = 0, depth = 0, aim = 0, move;
    string action;
    while (cin >> action >> move) {
        if (action == "forward") {
            initialX += move;
            depth += aim * move;
        } else if (action == "up") {
            aim -= move;
        } else if (action == "down") {
            aim += move;
        }
    }
    cout << depth * initialX;
    return 0;
}