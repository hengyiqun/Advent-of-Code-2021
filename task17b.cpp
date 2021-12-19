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
        
    int minT, maxT, distX, distY;
    set<pair<int, int>> ans;
    for (int xi = minXi; xi <= maxXi; ++xi) {
        for (int yi = minYi; yi <= maxYi; ++yi) {
            if (yi > 0) {
                maxT = ((-1 - 2*yi) + sqrt((2*yi + 1) * (2*yi + 1) - 8 * y1)) / 2;
                maxT += yi * 2 + 1;
                minT = ((-1 - 2*yi) + sqrt((2*yi + 1) * (2*yi + 1) - 8 * y2)) / 2;
                minT += yi * 2 + 1;
            } else {
                maxT = ((1 + 2*yi) + sqrt((2*yi + 1) * (2*yi + 1) - 8 * y1)) / 2;
                minT = ((1 + 2*yi) + sqrt((2*yi + 1) * (2*yi + 1) - 8 * y2)) / 2;
            }
            for (int t = minT; t <= maxT; ++t) {
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

    // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2;
    return 0;
}


/*


For positive yi:
After t1 = 2 * yi + 1, the vertical position of the probe will be back to starting value of 0.
After another t2 seconds, let the probe be at -(y+1)-(y+2)-...-(y+t) =  y1
Then (-y-1-y-t)*t/2 = y1        =>      t2 = ((-1-2*y) + sqrt((1+2*y)^2 - 8*y1)) / 2
Therefore tmax = 2 * yi + 1 + ((-1 - 2*y) + sqrt((1 + 2*y)^2 - 8*y1)) / 2

Similarly, tmin = 2 * yi + 1 + ((-1 - 2*y) + sqrt((1 + 2*y)^2 - 8*y2)) / 2


For negative yi
let y + (y-1) + ... + (y-t+1) = y1
Then (y + y - t + 1) * t / 2 = y1       =>      t = ((1 + 2*y) + sqrt((1 + 2*y)^2 - 8*y1)) / 2
Therefore tmax = ((1 + 2*y) + sqrt((1 + 2*y)^2 - 8*y1)) / 2

Similarly, tmin = ((1 + 2*y) + sqrt((1 + 2*y)^2 - 8*y2)) / 2

*/