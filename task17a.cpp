#include <bits/stdc++.h>
using namespace std;

int sumBetween(int start, int end) {
    return (start + end) * (end - start + 1) / 2;
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

    int yi = -y1 - 1;
    int highestHeight = sumBetween(1, yi);
    cout << highestHeight << '\n';

    // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2;
    return 0;
}


/*
In twice the time the probe reaches the highest height, it will return to its original height of y = 0.
The greastest height reaches by the probe occurs, if and only if, in the next step described by the above situation, the probe reaches the minimum y in the target region.
*/