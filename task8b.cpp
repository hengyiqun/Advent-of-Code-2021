#include <bits/stdc++.h>
using namespace std;

char diff(string a, string b) {
    string temp;
    if (a.size() < b.size()) {      // let b be the smaller string
        temp = a;
        a = b;
        b = temp;
    }

    char res;
    for (int i = 0; i < a.size(); ++i) {
        bool found = false;
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            res = a[i];
            break;
        }
    }

    return res;
}

bool subDigit(string a, string b) {
    if (a.size() > b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); ++i) {
        bool possible = false;
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                possible = true;
            }
        }
        if (!possible) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line, front, digits;
    int total = 0;
    while (getline(cin, line)) {
        front = line.substr(0, line.find("|"));
        stringstream ss1(front);
        
        unordered_map<int, vector<string>> umap;
        for (string cur; ss1 >> cur;) {
            sort(cur.begin(), cur.end());
            umap[cur.size()].push_back(cur);
        }

        unordered_map<char, int> alphabet;
        char top = diff(umap[2][0], umap[3][0]);
        alphabet[top] = 1;

        char topRight, bottomLeft, bottom, topLeft, middle;
        for (int i = 0; i < umap[6].size(); ++i) {
            if (!subDigit(umap[3][0], umap[6][i])) {     // umap[3][0] is 7 and umap[6][i] is 6
                topRight = diff(umap[6][i], umap[7][0]);        // umap[7][0] is 8      (comparing 6 and 8)
                
                for (int j = 0; j < umap[5].size(); ++j) {
                    if (subDigit(umap[5][j], umap[6][i])) {     // umap[5][j] is 5

                        bottomLeft = diff(umap[5][j], umap[6][i]);      //  comparing 6 and 5

                        for (int k = 0; k < umap[6].size(); ++k) {
                            if (k != i && subDigit(umap[5][j], umap[6][k])) {     // umap[6][k] is 9

                                string temp = umap[4][0];
                                temp.push_back(top);
                                bottom = diff(temp, umap[6][k]);

                                for (int p = 0; p < umap[5].size(); ++p) {
                                    
                                    if (p != j && subDigit(umap[5][p], umap[6][k])) {     // umap[5][p] is 3
                                        topLeft = diff(umap[5][p], umap[6][k]);     // comparing 3 and 9
            
                                    }
                                }


                                for (int p = 0; p < umap[6].size(); ++p) {       // umap[5][p] is 0
                                    if ( p != k && p != i && subDigit(umap[6][p], umap[7][0])) {     // umap[5][p] is 3
                                        middle = diff(umap[6][p], umap[7][0]);
            
                                    }
                                }
                            }
                        }
                    }
                }

            }   // else umap[6][i] is 0 or 9
        }
        alphabet[topRight] = 3;
        alphabet[bottomLeft] = 5;
        alphabet[bottom] = 7;
        alphabet[topLeft] = 2;
        alphabet[middle] = 4;

        string topRightBar(1, topRight);
        char bottomRight = diff(topRightBar, umap[2][0]);
        alphabet[bottomRight] = 6;

        /*for (auto &[k, v]: alphabet) {
            cout << k << ' ' << v << '\n';
        }*/


        /*for (auto &[k, v]: umap) {
            cout << k << ' ';
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }*/
        unordered_map<string, int> num;

        string one = string(1, topRight); one.push_back(bottomRight); sort(one.begin(), one.end());
        string seven = one; seven.push_back(top); sort(seven.begin(), seven.end());
        string four = one; four.push_back(topLeft); four.push_back(middle); sort(four.begin(), four.end());
        string two = string(1, top); two.push_back(topRight); two.push_back(middle); two.push_back(bottomLeft); two.push_back(bottom); sort(two.begin(), two.end());
        string three = seven; three.push_back(middle); three.push_back(bottom); sort(three.begin(), three.end());
        string five = string(1, top); five.push_back(topLeft); five.push_back(middle); five.push_back(bottomRight); five.push_back(bottom); sort(five.begin(), five.end());
        string six = five; six.push_back(bottomLeft); sort(six.begin(), six.end());
        string nine = five; nine.push_back(topRight); sort(nine.begin(), nine.end());
        string zero = seven; zero.push_back(topLeft); zero.push_back(bottomLeft); zero.push_back(bottom); sort(zero.begin(), zero.end());
        string eight = nine; eight.push_back(bottomLeft); sort(eight.begin(), eight.end());

        num[one] = 1;
        num[two] = 2;
        num[three] = 3;
        num[four] = 4;
        num[five] = 5;
        num[six] = 6;
        num[seven] = 7;
        num[eight] = 8;
        num[nine] = 9;
        num[zero] = 0;

        digits = line.substr(line.find("|") + 1);
        stringstream ss(digits);
        int curNum = 0, curMult = 1000;
        for (string cur; ss >> cur;) {
            sort(cur.begin(), cur.end());
            curNum += num[cur] * curMult;
            curMult /= 10;
        }

        total += curNum;
        //cout << curNum << '\n';
    }
    cout << total;
    return 0;
}

/*

    1
2       3
    4
5       6
    7

*/