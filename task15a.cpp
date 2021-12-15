#include <bits/stdc++.h>
using namespace std;

#define MAX_DIST 1e9

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board;
    vector<vector<int>> dist;
    string line;
    while (getline(cin, line)) {
        board.push_back(vector<int>(line.size()));
        dist.push_back(vector<int>(line.size()));
        for (int i = 0; i < line.size(); ++i) {
            board[board.size() - 1][i] = line[i] - '0';
            dist[dist.size() - 1][i] = MAX_DIST;
        }
    }
    int maxRow = board.size(), maxCol = board[0].size();
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
    /*for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }*/
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