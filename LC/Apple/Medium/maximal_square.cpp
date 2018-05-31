/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

In this problem, we define the state to be the maximal size of the square that can be achieved at point (i, j), denoted as P[i][j].

First, it is obvious that for the topmost row (i = 0) and the leftmost column (j = 0), P[i][j] = matrix[i][j]. Let's suppose that the topmost row of matrix is like [1, 0, 0, 1]. Then we can immediately know that the first and last point can be a square of size 1 while the two middle points cannot make any square, giving a size of 0. Thus, P = [1, 0, 0, 1], which is the same as matrix. The case is similar for the leftmost column. Till now, the boundary conditions of this DP problem are solved.

Let's move to the more general case for P[i][j] in which i > 0 and j > 0. First of all, let's see another simple case in which matrix[i][j] = 0. It is obvious that P[i][j] = 0 too. Why? Well, since matrix[i][j] = 0, no square will contain matrix[i][j]. According to our definition of P[i][j], P[i][j] is also 0.

Now we are almost done. The only unsolved case is matrix[i][j] = 1. Let's see an example.

Suppose matrix = [[0, 1], [1, 1]], it is obvious that P[0][0] = 0, P[0][1] = P[1][0] = 1, what about P[1][1]? Well, to give a square of size larger than 1 in P[1][1], all of its three neighbors (left, up, left-up) should be non-zero, right? In this case, the left-up neighbor P[0][0] = 0, so P[1][1] can only be 1, which means that it contains the square of itself.

Now you are near the solution. In fact, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1 in this case.

Taking all these together, we have the following state equations.

P[0][j] = matrix[0][j] (topmost row);
P[i][0] = matrix[i][0] (leftmost column);
For i > 0 and j > 0: if matrix[i][j] = 0, P[i][j] = 0; if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1.
*/

#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() < 1 || matrix[0].size() < 1)
        return 0;

    int ret = 0, i = 0, j = 0, r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> store(r, vector<int>(c, 0));

    for (i = 0; i < r; i++) {
        store[i][0] = matrix[i][0] - '0';
        ret = max(ret, store[i][0]);
    }

    for (i = 0; i < c; i++) {
        store[0][i] = matrix[0][i] - '0';
        ret = max(ret, store[0][i]);
    }

    for (i = 1; i < r; i++) {
        for (j = 1; j < c; j++) {
            if (matrix[i][j] == '1') {
                store[i][j] = min(store[i][j - 1], min(store[i - 1][j], store[i - 1][j - 1])) + 1;
                ret = max(ret, store[i][j]);
            }
        }
    }
    return ret*ret;
}

int main() {
    vector<vector<char>> matrix;
    vector<char> temp;
    int i, j, m, n;
    char x;

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

    cout << "\n Area: " << maximalSquare(matrix);

    cout << "\n\n";
    return 0;
}
