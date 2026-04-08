#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 9; i++) {
        unordered_set<char> s;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                if (s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            if (board[i][j] != '.') {
                if (s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
    }

    // Check 3x3 subgrids
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            unordered_set<char> s;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = board[boxRow + i][boxCol + j];
                    if (val != '.') {
                        if (s.count(val)) return false;
                        s.insert(val);
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    // vector<vector<char>> board = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}
    // };
     vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku (9 rows, use . for empty):\n";

    for (int i = 0; i < 9; i++) {
        string row;
        cin >> row;  // input like: 53..7....
        for (int j = 0; j < 9; j++) {
            board[i][j] = row[j];
        }
    }

    if (isValidSudoku(board))
        cout << "Valid Sudoku\n";
    else
        cout << "Invalid Sudoku\n";

    return 0;
}