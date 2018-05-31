/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;

    parent[node] = findParent(parent[node], parent);
    return parent[node];
}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> parent(m * n, -1), ret;
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    if (m < 1 || n < 1)
        return ret;

    if (positions.size() < 1)
        return vector<int>(1, 0);

    int i, j, k, l, node, neighbor, islandParent, count = 0;

    for (auto p : positions) {
        i = p.first;
        j = p.second;
        node = (i * n) + j;
        parent[node] = node;
        count += 1;
        for (auto d : direction) {
            k = i + d[0];
            l = j + d[1];
            neighbor = (k * n) + l;

            if (k < 0 || k > m - 1 || l < 0 || l > n - 1 || parent[neighbor] == -1)
                continue;

            islandParent = findParent(neighbor, parent);

            if (node != islandParent) {
                parent[node] = islandParent;
                node = islandParent;
                count -= 1;
            }
        }
        ret.push_back(count);
    }
    return ret;
}

int main() {
    int m, n, i, k, x, y;

    cout << "\n Enter (m, n, k): ";
    cin >> m >> n >> k;

    vector<pair<int, int>> positions;
    pair<int, int> temp;

    cout << "\n Enter positions: \n";

    for(i = 0; i < k; i++){
        cin >> temp.first >> temp.second;
        positions.push_back(temp);
    }

    vector<int> ret = numIslands2(m, n, positions);

    cout << "\n Number of Islands: ";
    for (i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";

    cout << "\n\n";
    return 0;
}
