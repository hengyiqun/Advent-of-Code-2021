#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line;
    cin >> line;
    vector<int> numZeros(line.size(), 0), numOnes(line.size(), 0);
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == '0') {
            numZeros[i]++;
        } else {
            numOnes[i]++;
        }
    }

    while (cin >> line) {
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '0') {
                numZeros[i]++;
            } else {
                numOnes[i]++;
            }
        }   
    }

    int gamma = 0, epsilon = 0;
    for (int i = 0; i < line.size(); ++i) {
        if (numZeros[i] > numOnes[i]) {
            epsilon += pow(2, line.size() - 1 - i);
        } else {
            gamma += pow(2, line.size() - 1 - i);
        }
    }
    cout << epsilon * gamma;
    return 0;
}