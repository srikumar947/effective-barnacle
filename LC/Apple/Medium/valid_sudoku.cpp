/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.

["5","3",".",".","7",".",".",".","."
["6",".",".","1","9","5",".",".","."
[".","9","8",".",".",".",".","6","."
["8",".",".",".","6",".",".",".","3"
["4",".",".","8",".","3",".",".","1"
["7",".",".",".","2",".",".",".","6"
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]

8 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
. . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/

#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> store(10, 0);
    int i, j, k, l;

    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                store[board[i][j] - '0'] += 1;
                if (store[board[i][j] - '0'] > 1)
                    return false;
            }
        }
        fill(store.begin(), store.end(), 0);
    }

    for (i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if (board[j][i] != '.') {
                store[board[j][i] - '0'] += 1;
                if (store[board[j][i] - '0'] > 1)
                    return false;
            }
        }
        fill(store.begin(), store.end(), 0);
    }

    for (k = 0; k < 7; k += 3) {
        for (l = 0; l < 7; l += 3) {
            for (i = k; i < k + 3; i++) {
                for (j = l; j < l + 3; j++) {
                    if (board[i][j] != '.') {
                        store[board[i][j] - '0'] += 1;
                        if (store[board[i][j] - '0'] > 1)
                            return false;
                    }
                }
            }
            fill(store.begin(), store.end(), 0);
        }
    }

    return true;
}

int main() {
    vector<vector<char>> matrix;
    vector<char> temp;
    int n = 9, i, j;
    char x;

    cout << "\n Enter the Matrix (row-wise): \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    cout << "\n Sudoku Board is valid: " << isValidSudoku(matrix);

    cout << "\n\n";
    return 0;
}
