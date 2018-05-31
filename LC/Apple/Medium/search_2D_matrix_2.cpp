/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Example 1:

Input: matrix, target = 5
Output: true
Example 2:

Input: matrix, target = 20
Output: false

1 4 7 11 15
2 5 8 12 19
3 6 9 16 22
10 13 14 17 24
18 21 23 26 30
*/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() < 1 || matrix[0].size() < 1)
        return false;

    int i, j, rows = matrix.size(), cols = matrix[0].size();

    i = 0;
    j = cols - 1;

    while(i < rows && j >= 0) {
        if (matrix[i][j] == target)
            return true;

        else if (matrix[i][j] > target)
            j--;

        else
            i++;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix;
    vector<int> temp;
    int n, m, i, j, x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    cout << "\n Enter the Matrix (row-wise): \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    cout << "\n\n Enter target: ";
    cin >> x;

    cout << "\n Element is Present: " << searchMatrix(matrix, x);

    cout << "\n\n";
    return 0;
}
