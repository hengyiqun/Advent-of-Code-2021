#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int curDepth, nextDepth, numIncrease = 0;
    cin >> curDepth;
    while (cin >> nextDepth) {
        if (nextDepth > curDepth) {
            numIncrease++;
        }
        curDepth = nextDepth;
    }
    cout << numIncrease;
    return 0;
}