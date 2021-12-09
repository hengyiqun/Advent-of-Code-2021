#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line;
    vector<vector<int>> caves;
    while (getline(cin, line)) {
        caves.push_back(vector<int> (line.size()));
        for (int i = 0; i < line.size(); ++i) {
            caves[caves.size() - 1][i] = line[i] - '0';
        }
    }

    int risk = 0, curHeight;
    for (int i = 1; i < caves.size() - 1; ++i) {
        for (int j = 1; j < caves[i].size() - 1; ++j) {
            curHeight = caves[i][j];
            if (caves[i-1][j] > curHeight && caves[i+1][j] > curHeight && caves[i][j+1] > curHeight && caves[i][j-1] > curHeight) {
                risk += curHeight + 1;
                //cout << i << ' ' << j << ' ' << curHeight << '\n';
            }
        }
    }

    for (int i = 1; i < caves.size() - 1; ++i) {
        curHeight = caves[i][0];
        if (caves[i-1][0] > curHeight && caves[i+1][0] > curHeight && caves[i][1] > curHeight) {
            risk += curHeight + 1;
            //cout << i << ' ' << 0 << ' ' << curHeight << '\n';
        }

        curHeight = caves[i][caves[i].size() - 1];
        if (caves[i-1][caves[i].size() - 1] > curHeight && caves[i+1][caves[i].size() - 1] > curHeight && caves[i][caves[i].size() - 2] > curHeight) {
            risk += curHeight + 1;
            //cout << i << ' ' << caves[i].size() - 1 << ' ' << curHeight << '\n';
        }
    }

    for (int j = 1; j < caves[0].size() - 1; ++j) {
        curHeight = caves[0][j];
        if (caves[1][j] > curHeight && caves[0][j-1] > curHeight && caves[0][j+1] > curHeight) {
            risk += curHeight + 1;
            //cout << 0 << ' ' << j << ' ' << curHeight << '\n';
        }

        curHeight = caves[caves.size() - 1][j];
        if (caves[caves.size() - 1][j-1] > curHeight && caves[caves.size() - 1][j+1] > curHeight && caves[caves.size() - 2][j] > curHeight) {
            risk += curHeight + 1;
            //cout << caves.size() - 1 << ' ' << j << ' ' << curHeight << '\n';
        }
    }

    if (caves[1][0] > caves[0][0] && caves[0][1] > caves[0][0]) {
        risk += caves[0][0] + 1;
        //cout << 0 << ' ' << 0 << caves[0][0] << '\n';
    }
    if (caves[caves.size() - 1][1] > caves[caves.size() - 1][0] && caves[caves.size() - 2][0] > caves[caves.size() - 1][0]) {
        risk += caves[caves.size() - 1][0] + 1;
        //cout << caves.size() - 1 << ' ' << 0 << caves[caves.size() - 1][0] << '\n';
    }
    if (caves[1][caves[0].size() - 1] > caves[0][caves[0].size() - 1] && caves[0][caves[0].size() - 2] > caves[0][caves[0].size() - 1]) {
        risk += caves[0][caves[0].size() - 1] + 1;
        //cout << 0 << ' ' << caves[0].size() - 1 << ' ' << caves[0][caves[0].size() - 1] << '\n';
    }
    if (caves[caves.size() - 2][caves[0].size() - 1] > caves[caves.size() - 1][caves[0].size() - 1] && caves[caves.size() - 1][caves[0].size() - 2] > caves[caves.size() - 1][caves[0].size() - 1]) {
        risk += caves[caves.size() - 1][caves[0].size() - 1] + 1;
        //cout << caves.size() - 1 << ' ' << caves[0].size() - 1 << ' ' << caves[caves.size() - 1][caves[0].size() - 1] << '\n';
    }

    cout << risk;
    return 0;
}
