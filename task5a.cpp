#include <bits/stdc++.h>
using namespace std;

class Point {
    private:
        int x;
        int y;
    
    public:
        Point() {}

        Point(int xi, int yi) {
            this->x = xi;
            this->y = yi;
        }

        int getX() {
            return this->x;
        }

        int getY() {
            return this->y;
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line;
    int x, y;
    vector<Point> points;
    while (cin >> line) {
        stringstream ss(line);
        for (int x; ss >> x;) {
            while (ss.peek() == ',' || ss.peek() == '-' || ss.peek() == '>') {
                ss.ignore();
            }
            ss >> y;
            Point point(x, y);
            points.push_back(point);
        }
    }
    vector<vector<int>> board(1000, vector<int>(1000, 0));
    Point curPoint, nextPoint;
    int curX, curY, nextX, nextY;
    for (int i = 0; i < points.size() / 2; ++i) {
        curPoint = points[2*i];
        curX = curPoint.getX();
        curY = curPoint.getY();
        nextPoint = points[2*i+1];
        nextX = nextPoint.getX();
        nextY = nextPoint.getY();
        //cout << curX << ' ' << curY << ' ' << nextX << ' ' << nextY << '\n';
        if (curX == nextX) {
            for (int i = min(curY, nextY); i <= max(curY, nextY); ++i) {
                board[curX][i]++;
            }
        } else if (curY == nextY) {
            for (int i = min(curX, nextX); i <= max(curX, nextX); ++i) {
                board[i][curY]++;
            }
        }
    }

    int numOverlaps = 0;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            if (board[i][j] >= 2) {
                numOverlaps++;
            }
        }
    }
    cout << numOverlaps;
    return 0;
}