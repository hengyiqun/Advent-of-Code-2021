#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    deque<int> dq;
    int next, curSum = 0, nextSum;
    for (int i = 0; i < 3; ++i) {
        cin >> next;
        curSum += next;
        dq.push_back(next);
    }
    nextSum = curSum;
    int numIncrease = 0;
    while (cin >> next) {
        nextSum -= dq.front();
        dq.pop_front();
        nextSum += next;
        dq.push_back(next);
        if (nextSum > curSum) {
            numIncrease++;
        }
        cout << curSum << ' ' << nextSum << '\n';
        curSum = nextSum;
    }
    cout << numIncrease;
    return 0;
}