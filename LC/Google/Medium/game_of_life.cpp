/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

#include <iostream>
#include <vector>

using namespace std;

// In place solution. O(1) space and O(m*n) time.
void gameOfLife(vector<vector<int>>& board) {
    if (board.size() < 1)
        return;

    int m = board.size(), n = board[0].size(), i = 0, j = 0, k = 0, l = 0, count = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            count = 0;
            for (k = max(0, i - 1); k < min(m, i + 2); k++) {
                for (l = max(0, j - 1); l < min(n, j + 2); l++) {
                    if (board[k][l] > 1)
                        count += board[k][l] - 2;
                    else
                        count += board[k][l];
                }
            }
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] += 2;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] > 1)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}

// Uses a duplicate board. O(m*n) space and O(m*n) time.
void gameOfLife2(vector<vector<int>>& board) {
    if (board.size() < 1)
        return;

    vector<vector<int>> duplicate = board;
    int m = board.size(), n = board[0].size(), i = 0, j = 0, k = 0, l = 0, count = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            count = 0;
            for (k = max(0, i - 1); k < min(m, i + 2); k++)
                for (l = max(0, j - 1); l < min(n, j + 2); l++)
                    if (duplicate[k][l] == 1)
                        count += duplicate[k][l];

            count -= duplicate[i][j];

            if (board[i][j]) {
                if (count == 2 || count == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
            else {
                if (count == 3)
                    board[i][j] = 1;
            }
        }
    }
}

int main () {
    int m, n, x, i, j;
    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    vector<vector<int>> board;
    vector<int> temp;

    cout << "\n Enter values row-wise (either dead (0) or live (1)): \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        board.push_back(temp);
        temp.clear();
    }

    gameOfLife2(board);

    cout << "\n Updated board is - \n ";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n ";
    }

    cout << "\n\n";
}
