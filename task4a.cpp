#include <bits/stdc++.h>
using namespace std;

class Bingo {
    public:
        vector<vector<int>> board;
        vector<vector<bool>> marked;

    public:
        Bingo(vector<vector<int>> grid) {
            this->board = grid;
            this->marked.assign(grid.size(), vector<bool>(grid[0].size(), false));
        }

        void mark(int n) {
            for (int i = 0; i < this->board.size(); ++i) {
                for (int j = 0; j < this->board[i].size(); ++j) {
                    if (this->board[i][j] == n) {
                        this->marked[i][j] = true;
                    }
                    //cout << this->marked[i][j] << ' ';
                }
                //cout << '\n';
            }
        }

        bool hasWon() {
            bool won;
            for (int i = 0; i < this->marked.size(); ++i) {       // check row
                won = true;
                for (int j = 0; j < this->marked[i].size(); ++j) {
                    if (!this->marked[i][j]) {
                        won = false;
                        break;
                    }
                }
                if (won) {
                    return true;
                }
            }

            for (int i = 0; i < this->marked[0].size(); ++i) {
                won = true;
                for (int j = 0; j < this->marked.size(); ++j) {
                    if (!this->marked[j][i]) {
                        won = false;
                        break;
                    }
                }
                if (won) {
                    return true;
                }
            }

            return false;
        }

        int calculateSum(int lastInput) {
            int sum = 0;
            for (int i = 0; i < this->marked.size(); ++i) {
                for (int j = 0; j < this->marked[i].size(); ++j) {
                    if (!this->marked[i][j]) {
                        sum += this->board[i][j];
                    }
                }
            }
            return sum * lastInput;
        }

        void printBingo() {
            for (int i = 0; i < this->marked.size(); ++i) {
                for (int j = 0; j < this->marked[i].size(); ++j) {
                    cout << this->marked[i][j] << ' ';
                }
                cout << '\n';
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string line; cin >> line;
    vector<int> input;

    stringstream ss(line);
    for (int i; ss >> i;) {
        input.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

    /*for (int i = 0; i < input.size(); ++i) {
        cout << input[i] << ' ';
    }
    cout << '\n';*/

    vector<Bingo> allBingos;
    int num;
    while (cin >> num) {
        vector<vector<int>> cur(5, vector<int>(5));
        cur[0][0] = num;
        for (int i = 1; i < 5; ++i) {
            cin >> cur[0][i];
        }

        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                cin >> cur[i][j];
            }
        }

        Bingo curBingo(cur);
        allBingos.push_back(curBingo);
    }

    int winningBingo = 1e9, curInput;
    for (int i = 0; i < input.size(); ++i) {
        curInput = input[i];
        for (int j = 0; j < allBingos.size(); ++j) {
            allBingos[j].mark(curInput);
            if (allBingos[j].hasWon()) {
                winningBingo = j;
                break;
            }
        }
        if (winningBingo != 1e9) {
            break;
        }
    }

    /*
        Do not do the below, as it will create another Bingo:

            Bingo curBingo = allBingos[j];
            curBingo.mark(input[i]);
            if (curBingo.hasWon()) {
                winningBingo = j;
                break;
            }
    */

    cout << allBingos[winningBingo].calculateSum(curInput);

    return 0;
}