#include <bits/stdc++.h>
using namespace std;

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
    int position = pos[pos.size() / 2];
    int numFuel = 0;
    for (int i = 0; i < pos.size(); ++i) {
        numFuel += abs(position - pos[i]);
    }
    cout << numFuel;
    return 0;
}

/*
If you have an odd number of items, then the one in the middle will be your optimum.

If you have an even number, any number between the central two will be equally optimal.

Explanation: to move your resulting number will change each of the abs(x-x1) by the same amount, but with different signs: some increasing and some decreasing.

From the point in the center (in the odd case) there will be one more increasing abs when moving in either direction; while when moving between the two central points (in the even case) there will be equally many abs of each sign.
*/