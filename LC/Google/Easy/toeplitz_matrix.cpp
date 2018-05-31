/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    if (matrix.size() <= 1)
        return true;

    int i = 0, j = 0, rows = matrix.size(), cols = matrix[0].size();

    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < cols - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1])
                return false;
        }
    }

    return true;
}

int main () {
    vector<vector<int>> mat;
    vector<int> add;
    int x, n, i, m, j;

    cout << "\n Enter number of rows: ";
    cin >> m;

    cout << "\n Enter number of cols: ";
    cin >> n;

    for (i = 0; i < m; i++) {
        cout << "\n Enter row " << i + 1 << " - ";
        for (j = 0; j < n; j++) {
            cin >> x;
            add.push_back(x);
        }
        mat.push_back(add);
        add.clear();
    }


    cout << "\n Toeplitz: " << isToeplitzMatrix(mat);

    cout << "\n\n";
}
