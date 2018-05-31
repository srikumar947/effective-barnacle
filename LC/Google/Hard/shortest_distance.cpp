/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int shortestDistance(vector<vector<int>>& grid) {
    int rows = grid.size();
    if (rows < 1)
        return -1;
    int cols = grid[0].size();
    if (cols < 1)
        return -1;

    vector<vector<int>> distance(rows, vector<int>(cols, 0)), reachable(rows, vector<int>(cols, 0)), directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int ret = INT_MAX, buildings = 0, i = 0, j = 0, k = 0, l = 0, d = 0, x = 0, y = 0;
    pair<int, int> temp;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                buildings += 1;
                d = 0;
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                queue<pair<int, int>> current_level, next_level;
                current_level.emplace(i, j);
                while (!current_level.empty()) {
                    d += 1;
                    while (!current_level.empty()) {
                        temp = current_level.front();
                        current_level.pop();
                        x = temp.first;
                        y = temp.second;
                        reachable[x][y] += 1;
                        for (auto dir : directions) {
                            k = x + dir[0];
                            l = y + dir[1];
                            if (k >= 0 && k <= rows - 1 && l >= 0 && l <= cols - 1 && grid[k][l] == 0 && !visited[k][l]) {
                                distance[k][l] += d;
                                next_level.emplace(k, l);
                                visited[k][l] = true;
                            }
                        }
                    }
                    swap(current_level, next_level);
                }
            }
        }
    }

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (grid[i][j] == 0 && reachable[i][j] == buildings)
                ret = min(ret, distance[i][j]);

    return ret == INT_MAX ? -1 : ret;
}

int main() {
    vector<vector<int>> grid;
    vector<int> temp;
    int n, m, i, j, x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    cout << "\n Enter the elements (grid): \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
        temp.clear();
    }

    cout << "\n Shortest Distance: " << shortestDistance(grid);

    cout << "\n\n";
    return 0;
}
