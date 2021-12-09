#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll initialX = 0, depth = 0, move;
    string action;
    while (cin >> action >> move) {
        if (action == "forward") {
            initialX += move;
        } else if (action == "up") {
            depth -= move;
        } else if (action == "down") {
            depth += move;
        }
    }
    cout << depth * initialX;
    return 0;
}