#include <bits/stdc++.h>
using namespace std;

#define MAX_DIST 1e9

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board;
    string line;
    while (getline(cin, line)) {
        board.push_back(vector<int>(5 * line.size()));
        for (int i = 0; i < line.size(); ++i) {
            board[board.size() - 1][i] = line[i] - '0';
        }
        for (int t = 1; t < 5; ++t) {
            for (int i = 0; i < line.size(); ++i) {
                board[board.size() - 1][t*line.size() + i] = ((board[board.size() - 1][(t-1)*line.size() + i] + 1) % 10);
                if (board[board.size() - 1][t*line.size() + i] == 0) {
                    board[board.size() - 1][t*line.size() + i]++;
                }
            }
        }
    }
    int maxRow = board.size(), maxCol = board[0].size();
    for (int t = 1; t < 5; ++t) {
        for (int i = 0; i < maxRow; ++i) {
            board.push_back(vector<int>(board[0].size()));
            for (int j = 0; j < maxCol; ++j) {
                board[board.size() - 1][j] = (board[board.size() - 1 - maxRow][j] + 1) % 10;
                if (board[board.size() - 1][j] == 0) {
                    board[board.size() - 1][j]++;
                }
            }
        }
    }
    maxRow = board.size();

    /*for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxCol; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }*/
    vector<vector<int>> dist(maxRow, vector<int>(maxCol, MAX_DIST));
    
    dist[0][0] = 0;
    int horiz[4] = {0, 1, 0, -1};
    int verti[4] = {1, 0, -1, 0};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push(make_tuple(0, 0, 0));
    int newR, newC;
    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();
        if (d > dist[r][c]) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            newR = r + verti[i];
            newC = c + horiz[i];
            if (newR >= 0 && newR < maxRow && newC >= 0 && newC < maxCol) {
                if (dist[r][c] + board[newR][newC] >= dist[newR][newC]) {
                    continue;
                }
                dist[newR][newC] = dist[r][c] + board[newR][newC];
                pq.push(make_tuple(dist[newR][newC], newR, newC));
            }
        }
    }
    cout << dist[maxRow - 1][maxCol - 1];
    /*cout << '\n';
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << dist[i][j];
        }
        cout << '\n';
    }*/
    return 0;
}