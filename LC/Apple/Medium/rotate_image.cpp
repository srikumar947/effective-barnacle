/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    if (!matrix.size())
        return;

    int i, j, r = matrix.size(), c = matrix[0].size(), temp;

    for (i = 0; i < r; i++) {
        for (j = i; j < c; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (i = 0; i < c; i++) {
        for (j = 0; j < r/2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][r - j - 1];
            matrix[i][r - j - 1] = temp;
        }
    }
}

int main() {
    vector<vector<int>> matrix;
    vector<int> temp;
    int n, i, j, x;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter the Matrix (row-wise): \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    rotate(matrix);

    cout << "\n Rotated Matrix: \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";
    return 0;
}
