#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &caves, int curRow, int curCol, int numRow, int numCol, int curNum) {
    caves[curRow][curCol] = curNum;
    int horiz[4] = {1, -1, 0, 0};
    int verti[4] = {0, 0, 1, -1};
    int newRow, newCol;
    for (int i = 0; i < 4; ++i) {
        newRow = curRow + verti[i];
        newCol = curCol + horiz[i];
        if (newRow >= 0 && newRow < numRow && newCol >= 0 && newCol < numCol) {
            if (caves[newRow][newCol] >= 0 && caves[newRow][newCol] != 9) {
                dfs(caves, newRow, newCol, numRow, numCol, curNum);
            }
        }
    }
}

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
    int numRow = caves.size(), numCol = caves[0].size();

    int curNum = -1;
    for (int i = 0; i < numRow; ++i) {
        for (int j = 0; j < numCol; ++j) {
            if (caves[i][j] >= 0 && caves[i][j] != 9) {
                dfs(caves, i, j, numRow, numCol, curNum);
                curNum--;
            }
        }
    }
    
    vector<int> ans(abs(curNum), 0);
    for (int i = 0; i < numRow; ++i) {
        for (int j = 0; j < numCol; ++j) {
            if (caves[i][j] < 0) {
                ans[abs(caves[i][j])]++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    int res = ans[ans.size() - 1] * ans[ans.size() - 2] * ans[ans.size() - 3];
    cout << res;
    return 0;
}