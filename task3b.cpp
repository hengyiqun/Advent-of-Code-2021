#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line;
    vector<string> more, less;
    while (cin >> line) {
        more.push_back(line);
        less.push_back(line);
    }

    int curIndex = 0, numZeros, numOnes;
    while (more.size() > 1) {
        numZeros = 0;
        numOnes = 0;
        vector<string> temp0, temp1;
        for (int i = 0; i < more.size(); ++i) {
            if (more[i][curIndex] == '0') {
                numZeros++;
                temp0.push_back(more[i]);
            } else {
                numOnes++;
                temp1.push_back(more[i]);
            }
        }
        curIndex++;

        if (numOnes >= numZeros) {
            more = temp1;
        } else {
            more = temp0;
        }
    }

    int oxygen = 0;
    for (int i = 0; i < more[0].size(); ++i) {
        if (more[0][i] == '1') {
            oxygen += pow(2, more[0].size() - 1 - i);
        }
    }

    curIndex = 0;
    while (less.size() > 1) {
        numZeros = 0;
        numOnes = 0;
        vector<string> temp0, temp1;
        for (int i = 0; i < less.size(); ++i) {
            if (less[i][curIndex] == '0') {
                numZeros++;
                temp0.push_back(less[i]);
            } else {
                numOnes++;
                temp1.push_back(less[i]);
            }
        }
        curIndex++;

        if (numOnes >= numZeros) {
            less = temp0;
        } else {
            less = temp1;
        }
    }

    int co2 = 0;
    for (int i = 0; i < less[0].size(); ++i) {
        if (less[0][i] == '1') {
            co2 += pow(2, less[0].size() - 1 - i);
        }
    }

    cout << oxygen * co2;
    return 0;
}