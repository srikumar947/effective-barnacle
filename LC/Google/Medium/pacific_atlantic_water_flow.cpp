/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& matrix, int **isVisited, int i, int j) {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int k, l, m = matrix.size(), n = matrix[0].size();

    isVisited[i][j] = 1;

    for (pair<int, int> coord:dir) {
        k = i + coord.first;
        l = j + coord.second;

        if (k < 0 || l < 0 || k > m - 1 || l > n - 1 || isVisited[k][l] == 1 || matrix[k][l] < matrix[i][j])
            continue;
        dfs(matrix, isVisited, k, l);
    }

}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    vector<pair<int, int>> ret;

    if (matrix.size() < 1)
        return ret;

    int m = matrix.size(), n = matrix[0].size(), i, j;

    int **pacific, **atlantic;

    pacific = new int*[m];
    for (i = 0; i < m; i++)
        pacific[i] = new int[n]();

    atlantic = new int*[m];
    for (i = 0; i < m; i++)
        atlantic[i] = new int[n]();

    for (i = 0; i < m; i++) {
        dfs(matrix, pacific, i, 0);
        dfs(matrix, atlantic, i, n - 1);
    }

    for (j = 0; j < n; j++) {
        dfs(matrix, pacific, 0, j);
        dfs(matrix, atlantic, m - 1, j);
    }

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (pacific[i][j] && atlantic[i][j]) {
                pair<int, int> coord;
                coord.first = i;
                coord.second = j;
                ret.push_back(coord);
            }

    return ret;
}


int main () {
    int m, n, i, j, x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m);

    cout << "\n Enter Values (row-wise): ";

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> x;
            matrix[i].push_back(x);
        }
    }

    vector<pair<int, int>> ret = pacificAtlantic(matrix);

    for (i = 0; i < ret.size(); i++)
        cout << "\n (x, y): " << "(" << ret[i].first << ", " << ret[i].second << ")";

    cout << "\n\n";
}
