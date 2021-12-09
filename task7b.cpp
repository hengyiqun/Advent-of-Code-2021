#include <bits/stdc++.h>
using namespace std;

int sumToN(int n) {
    return n * (n + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line; getline(cin, line);
    vector<int> pos;
    stringstream ss(line);
    for (int i; ss >> i;) {
        pos.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }
    sort(pos.begin(), pos.end());

    unordered_map<int, int> count;
    for (int i = 0; i < pos.size(); ++i) {
        if (count.find(pos[i]) == count.end()) {
            count[pos[i]] = 1;
        } else {
            count[pos[i]]++;
        }
    }

    int curFuel = 0, leftDiff = 0, rightDiff = 0;
    for (int i = 0; i < pos.size(); ++i) {
        curFuel += sumToN(abs(pos[i] - pos[0]));
        rightDiff += abs(pos[i] - pos[0]);
        //cout << pos[i] << ' ';
    }
    //cout << '\n';
    int leftSum = 0, rightSum = curFuel, minFuel = curFuel;
    int numLeft, numRight;
    int curIndex;
    for (int i = 0; i < pos.size() && pos[i] == pos[0]; ++i) {
        curIndex = i + 1;
        leftDiff += pos[i] - pos[0];
        rightDiff -= pos[i] - pos[0];
    }
    numLeft = curIndex;
    numRight = pos.size() - numLeft;

    
    //cout << leftDiff << ' ' << rightDiff << ' ' << leftSum << ' ' << rightSum << '\n';
    for (int i = pos[0] + 1; i <= pos[pos.size() - 1]; ++i) {
        rightSum -= rightDiff;
        rightDiff -= numRight;

        leftDiff += numLeft;
        leftSum += leftDiff;
        if (pos[curIndex] == i) {
            numLeft += count[pos[curIndex]];
            numRight -= count[pos[curIndex]];
            curIndex += count[pos[curIndex]];
        }
        //cout << leftDiff << ' ' << rightDiff << ' ' << leftSum << ' ' << rightSum << '\n';
        curFuel = leftSum + rightSum;
        minFuel = min(curFuel, minFuel);
    }
    cout << minFuel;
    return 0;
}
// 0 1 1 2 2 2 4 7 14 16 

//1 + 1 * 3 + (1 + 2) + 21 + 91 + 120
