/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.

Your NumMatrix object will be instantiated and called as such:
NumMatrix obj = new NumMatrix(matrix);
obj.update(row,col,val);
int param_2 = obj.sumRegion(row1,col1,row2,col2);

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> colSum;

    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1)
            return;

        this->matrix = matrix;
        colSum.resize(matrix.size() + 1, vector<int>(matrix[0].size(), 0));

        for (int i = 1; i <= matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                colSum[i][j] = colSum[i - 1][j] + matrix[i - 1][j];
    }

    void update(int row, int col, int val) {
        for (int i = row + 1; i < colSum.size(); i++)
            colSum[i][col] = colSum[i][col] + val - matrix[row][col];
        matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int j = col1; j <= col2; j++)
            ret += colSum[row2 + 1][j] - colSum[row1][j];
        return ret;
    }
};

int main() {
    vector<vector<int>> matrix;
    vector<int> temp;
    int m, n, i, j, x;

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

    NumMatrix obj(matrix);

    cout << "\n Sum: " << obj.sumRegion(2, 1, 4, 3);

    obj.update(3, 2, 2);

    cout << "\n Sum: " << obj.sumRegion(2, 1, 4, 3);

    cout << "\n\n";
    return 0;
}
