/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16

0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0
*/

#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
	if (grid.size() < 1 || grid[0].size() < 1)
		return 0;

	int ret = 0, sub = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			sub = 0;
			if (grid[i][j] == 1) {
				if (j - 1 >= 0 && grid[i][j - 1])
					sub += 1;
				if (j + 1 < grid[0].size() && grid[i][j + 1])
					sub += 1;
				if (i - 1 >= 0 && grid[i - 1][j])
					sub += 1;
				if (i + 1 < grid.size() && grid[i + 1][j])
					sub += 1;
				ret += (4 - sub);
			}
		}
	}
	return ret;
}

int main () {
	vector<vector<int>> grid;
	vector<int> temp;
	int i, j, x, n, m;

	cout << "\n Enter (m, n): ";
	cin >> m >> n;


	cout << "\n Enter grid - \n";
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> x;
			temp.push_back(x);
		}
		grid.push_back(temp);
		temp.clear();
	}

	cout << "\n Perimter of the island is: " << islandPerimeter(grid);

	cout << "\n\n";
	return 0;
}
