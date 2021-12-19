#include <bits/stdc++.h>
using namespace std;

int calculateX(int xEnd) {
    return (-1 + sqrt(1 + 8*xEnd)) / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line; getline(cin, line);
    string temp = line.substr(line.find('x') + 2, line.find('.'));
    int x1 = stoi(temp);
    temp = line.substr(line.find('.') + 2, line.find(','));
    int x2 = stoi(temp);
    
    temp = line.substr(line.find('y') + 2, line.find('.'));
    int y1 = stoi(temp);
    
    temp = line.substr(line.find_last_of('.') + 1);
    int y2 = stoi(temp);

    int minYi = y1, maxYi = -y1 - 1;
    int minXi = calculateX(x1), maxXi = x2;
        
    int maxT, distX, distY;
    set<pair<int, int>> ans;
    for (int xi = minXi; xi <= maxXi; ++xi) {
        for (int yi = minYi; yi <= maxYi; ++yi) {
            if (yi > 0) {
                maxT = ((-1 - 2*yi) + sqrt((2*yi + 1) * (2*yi + 1) - 8 * y1)) / 2;
                maxT += yi * 2 + 1;
            } else {
                maxT = ((1 - 2*yi) + sqrt((2*yi - 1) * (2*yi - 1) - 8 * y1)) / 2;
            }
            for (int t = 0; t <= maxT; ++t) {
                if (t >= xi) {
                    distX = (xi + 1) * xi / 2;
                } else {
                    distX = (2 * xi - t + 1) * t / 2;
                }
                distY = (2 * yi - t + 1) * t / 2;
                if (x1 <= distX && distX <= x2 && y1 <= distY && distY <= y2) {
                    ans.insert(make_pair(xi, yi));
                }
            }
        }
    }
    
    /*for (int xi = 0; xi <= 500; ++xi) {
        for (int yi = -300; yi <= 500; ++yi) {
            for (int t = 0; t <= 300; ++t) {
                if (t >= xi) {
                    distX = (xi + 1) * xi / 2;
                } else {
                    distX = (2 * xi - t + 1) * t / 2;
                }
                distY = (2 * yi - t + 1) * t / 2;
                if (x1 <= distX && distX <= x2 && y1 <= distY && distY <= y2) {
                    ans.insert(make_pair(xi, yi));
                }
            }
        }
    }*/

    cout << ans.size() << '\n';

    cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2;
    return 0;
}