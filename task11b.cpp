#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board;
    string line;
    while (getline(cin, line)) {
        board.push_back(vector<int> (line.size()));
        for (int i = 0; i < line.size(); ++i) {
            board.back()[i] = line[i] - '0';
        }
    }
    int numRows = board.size(), numCols = board[0].size();
    int numFlash = 0;
    int horiz[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int verti[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int curTime = 0;
    bool synchronised = false;
    while (!synchronised) {
        curTime++;
        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j]++;
                if (board[i][j] > 9) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            numFlash++;
            pair<int, int> cur = q.front(); q.pop();
            int curRow = cur.first, curCol = cur.second;
            for (int k = 0; k < 8; ++k) {
                int newRow = curRow + verti[k];
                int newCol = curCol + horiz[k];
                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
                    board[newRow][newCol]++;
                    if (board[newRow][newCol] == 10) {
                        q.push(make_pair(newRow, newCol));
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] > 9) {
                    board[i][j] = 0;
                }
            }
        }

        int curNum = board[0][0];
        synchronised = true;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != curNum) {
                    synchronised = false;
                    break;
                }
            }
        }
    }
    cout << curTime;
    /*for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }*/
    return 0;
}