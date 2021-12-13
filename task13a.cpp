#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<int, int>> points;
    vector<pair<int, int>> fold;
    int r, c, maxR = 0, maxC = 0;
    string line, op;
    while (getline(cin, line)) {
        if (line.find(",") != string::npos) {
            c = stoi(line.substr(0, line.find(",")));
            r = stoi(line.substr(line.find(",") + 1));
            maxR = max(r, maxR);
            maxC = max(c, maxC);
            points.push_back(make_pair(r, c));
            //cout << r << ' ' << c << '\n';
        } else if (line.size() > 1) {
            op = line.substr(line.find("=") - 1);
            if (op[0] == 'x') {
                fold.push_back(make_pair(0, stoi(line.substr(line.find("=") + 1))));
            } else if (op[0] == 'y') {
                fold.push_back(make_pair(1, stoi(line.substr(line.find("=") + 1))));
            }
            //cout << fold.back().first << ' ' << fold.back().second << '\n';
        }
    }
    vector<vector<bool>> board(maxR + 1, vector<bool>(maxC + 1, false));
    pair<int, int> curPoint, curFold;
    for (int i = 0; i < points.size(); ++i) {
        curPoint = points[i];
        r = curPoint.first;
        c = curPoint.second;
        board[r][c] = true;
    }
    curFold = fold[0];
    int curAxis = curFold.first, curLine = curFold.second;
    int offset;
    if (curAxis == 0) {     // fold along x-axis
        for (int i = 0; i < maxR + 1; ++i) {
            for (int j = curLine + 1; j < maxC + 1; ++j) {
                if (board[i][j]) {
                    offset = j - curLine;
                    board[i][curLine - offset] = true;
                }
            }
        }
        maxC = curLine - 1;
    } else {    // fold along y-axis
        for (int i = curLine + 1; i < maxR +1; ++i) {
            for (int j = 0; j < maxC + 1; ++j) {
                if (board[i][j]) {
                    offset = i - curLine;
                    board[curLine - offset][j] = true;
                }
            }
        }
        maxR = curLine - 1;
    }

    int numDots = 0;
    for (int i = 0; i < maxR + 1; ++i) {
        for (int j = 0; j < maxC + 1; ++j) {
            if (board[i][j]) {
                numDots++;
            }
        }
    }
    cout << numDots;
    return 0;
}