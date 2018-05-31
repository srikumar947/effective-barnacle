/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache, vector<vector<int>>& directions, int& rows, int& cols) {
    int ret = 0;
    if (cache[i][j] != 0)
        return cache[i][j];

    for (auto d : directions) {
        int x = i + d[0], y = j + d[1];
        if (x >=0 && x < rows && y >= 0 && y < cols && matrix[x][y] > matrix[i][j])
            cache[i][j] = max(cache[i][j], dfs(matrix, x, y, cache, directions, rows, cols));
    }

    return ++cache[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows < 1)
        return 0;

    int ret = 0, cols = matrix[0].size();
    vector<vector<int>> cache(rows, vector<int>(cols, 0)), directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ret = max(ret, dfs(matrix, i, j, cache, directions, rows, cols));

    return ret;
}

int main() {
    vector<vector<int>> matrix;
    vector<int> temp;
    int n, m, i, j, x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    cout << "\n Enter the elements: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    cout << "\n Longest path: " << longestIncreasingPath(matrix);

    cout << "\n\n";
    return 0;
}
