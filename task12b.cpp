#include <bits/stdc++.h>
using namespace std;

bool isLower(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (!islower(s[i])) {
            return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>> &AL, vector<bool> visited, unordered_map<int, string> &umapRev, int curNode, int* numWays, bool visitTwice) {
    if (umapRev[curNode] == "end") {
        (*numWays)++;
        return;
    }
    if (isLower(umapRev[curNode])) {
        visited[curNode] = true;
    }
    for (auto &n: AL[curNode]) {
        if (umapRev[n] != "start") {
            if (!visited[n]) {
                dfs(AL, visited, umapRev, n, numWays, visitTwice);
            } else if (visited[n] && !visitTwice) {
                dfs(AL, visited, umapRev, n, numWays, true);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line;
    vector<vector<int>> AL;
    int curNode = 0;
    unordered_map<string, int> umap;
    unordered_map<int, string> umapRev;
    while (getline(cin, line)) {
        string node1, node2;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '-') {
                node1 = line.substr(0, i);
                node2 = line.substr(i+1);
            }
        }
        if (umap.find(node1) == umap.end()) {
            umap[node1] = curNode;
            umapRev[curNode] = node1;
            curNode++;
            AL.push_back(vector<int>());
        }
        if (umap.find(node2) == umap.end()) {
            umap[node2] = curNode;
            umapRev[curNode] = node2;
            curNode++;
            AL.push_back(vector<int>());
        }
        AL[umap[node1]].push_back(umap[node2]);
        AL[umap[node2]].push_back(umap[node1]);
    }
    int numWays = 0;
    int start = umap["start"];
    vector<bool> visited(curNode, false);
    dfs(AL, visited, umapRev, start, &numWays, false);
    cout << numWays;
    return 0;
}