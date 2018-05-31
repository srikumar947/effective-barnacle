/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

#include <iostream>
#include <vector>

using namespace std;

bool search(int i, int j, int x, int y, int m, int n, vector<vector<int>>& visited, vector<vector<int>>& maze, vector<string>& direction) {
    if (visited[i][j] != 1) {
        visited[i][j] = 1;

        for (auto d : direction) {
            int k = i, l = j;

            if (d == "l") {
                while (l >= 0) {
                    if (maze[k][l] == 1)
                        break;
                    l--;
                }
                l = l + 1;
            }

            else if (d == "r") {
                while (l < n) {
                    if (maze[k][l] == 1)
                        break;
                    l++;
                }
                l = l - 1;
            }

            else if (d == "u") {
                while (k >= 0) {
                    if (maze[k][l] == 1)
                        break;
                    k--;
                }
                k = k + 1;
            }

            else if (d == "d") {
                while (k < m) {
                    if (maze[k][l] == 1)
                        break;
                    k++;
                }
                k = k - 1;
            }

            if ((k == x && l == y) || search(k, l, x, y, m, n, visited, maze, direction))
                return true;
        }
    }
    return false;
}

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    if (!maze.size() || start.size() != 2 || destination.size() != 2)
        return false;

    int m = maze.size(), n = maze[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<string> direction = {"l", "r", "u", "d"};

    return search(start[0], start[1], destination[0], destination[1], m, n, visited, maze, direction);
}

int main() {
    vector<vector<int>> maze;
    vector<int> temp, start(2), destination(2);
    int n, m, i, j, x;

    cout << "\n Enter (m, n): ";
    cin >> m >> n;

    cout << "\n Enter the elements (row-wise): \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        maze.push_back(temp);
        temp.clear();
    }

    cout << "\n Enter start position (i, j): ";
    cin >> start[0] >> start[1];

    cout << "\n Enter destination (i, j): ";
    cin >> destination[0] >> destination[1];

    cout << "\n The maze has a path: " << hasPath(maze, start, destination);

    cout << "\n\n";
    return 0;
}
