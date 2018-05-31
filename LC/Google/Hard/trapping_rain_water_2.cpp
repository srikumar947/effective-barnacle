/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.size() < 1)
        return 0;

    int m = heightMap.size(), n = heightMap[0].size(), i, j, k, l, ret = 0, current_max = INT_MIN, height;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> visited(m, vector<int>(n, 0)), direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    pair<int, int> p;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                pq.push(make_pair(heightMap[i][j], (i * n) + j));
                visited[i][j] = 1;
            }

    while (!pq.empty()) {
        p = pq.top();
        pq.pop();

        height = p.first;
        i = p.second / n;
        j = p.second % n;

        current_max = max(current_max, height);

        for (auto d : direction) {
            k = i + d[0];
            l = j + d[1];

            if (k < 0 || k >= m || l < 0 || l >= n || visited[k][l])
                continue;

            visited[k][l] = 1;
            if (heightMap[k][l] < current_max)
                ret += current_max - heightMap[k][l];

            pq.push(make_pair(heightMap[k][l], (k * n) + l));
        }
    }

    return ret;
}

int main() {
    vector<vector<int>> heightMap;
    vector<int> temp;
    int n, m, i, j, x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    cout << "\n Enter the elements (row-wise): ";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        heightMap.push_back(temp);
        temp.clear();
    }

    x = trapRainWater(heightMap);

    cout << "\n Units Trapped: " << x;

    cout << "\n\n";
    return 0;
}
