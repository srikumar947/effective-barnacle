/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0

1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, vector<pair<int, int>> dir) {
    int k, l, m = grid.size(), n = grid[0].size();

    for (pair<int, int> coord:dir) {
        k = i + coord.first;
        l = j + coord.second;

        if (k < 0 || l < 0 || k > m - 1 || l > n - 1 || grid[k][l] == '0')
            continue;
        grid[k][l] = '0';
        dfs(grid, k, l, dir);
    }
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.size() < 1)
        return 0;

    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int i, j, m = grid.size(), n = grid[0].size(), ret = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j, dir);
                ret += 1;
            }
        }
    }

    return ret;
}


int main () {
    int m, n, i, j;
    char x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    vector<vector<char>> grid(m);

    cout << "\n Enter Values (row-wise): ";

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> x;
            grid[i].push_back(x);
        }
    }

    int ret = numIslands(grid);

    cout << "\n Number of Islands: " << ret;

    cout << "\n\n";
}
