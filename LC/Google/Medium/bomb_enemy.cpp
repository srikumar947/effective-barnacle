/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countEnemies(vector<vector<char>>& grid, int i, int j) {
    int ret = 0, k = 0, l = 0;

    for (k = i - 1, l = i + 1; k >= 0 || l < grid.size(); k--, l++) {
        if (k >= 0) {
            if (grid[k][j] == 'W')
                k = -1;
            else if (grid[k][j] == 'E')
                ret += 1;
        }

        if (l < grid.size()) {
            if (grid[l][j] == 'W')
                l = grid.size();
            else if (grid[l][j] == 'E')
                ret += 1;
        }
    }

    for (k = j - 1, l = j + 1; k >= 0 || l < grid[0].size(); k--, l++) {
        if (k >= 0) {
            if (grid[i][k] == 'W')
                k = -1;
            else if (grid[i][k] == 'E')
                ret += 1;
        }

        if (l < grid[0].size()) {
            if (grid[i][l] == 'W')
                l = grid[0].size();
            else if (grid[i][l] == 'E')
                ret += 1;
        }
    }

    return ret;
}

int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.size() < 1)
        return 0;

    int ret = 0, i = 0, j = 0, m = grid.size(), n = grid[0].size(), count;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == '0') {
                count = countEnemies(grid, i, j);
                ret = max(ret, count);
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

    int ret = maxKilledEnemies(grid);

    cout << "\n Maximum Number of enemies killed: " << ret;

    cout << "\n\n";
}
