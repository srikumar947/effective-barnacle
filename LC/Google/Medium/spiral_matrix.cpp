/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <iostream>
#include <vector>

using namespace std;

void generateSpiral(vector<vector<int>>& matrix, vector<int>& ret, int istart, int jstart, int iend, int jend) {
	if (istart <= iend && jstart <= jend) {
		int i = istart, j = jstart;

		for (j = jstart; j <= jend; j++)
			ret.push_back(matrix[istart][j]);

		for (i = istart + 1; i <= iend; i++)
			ret.push_back(matrix[i][jend]);

		if (istart < iend && jstart < jend) {
			for (j = jend - 1; j >= jstart; j--)
				ret.push_back(matrix[iend][j]);

			for (i = iend - 1; i > istart; i--)
				ret.push_back(matrix[i][jstart]);
		}

		generateSpiral(matrix, ret, istart + 1, jstart + 1, iend - 1, jend - 1);
	}
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() < 1 || matrix[0].size() < 1)
		return vector<int>(0);

	vector<int> ret;
	generateSpiral(matrix, ret, 0, 0, matrix.size() - 1, matrix[0].size() - 1);

	return ret;
}

int main () {
	int i, j, m, n, x;
	vector<int> temp;
	vector<vector<int>> matrix;

	cout << "\n Enter (m, n): ";
	cin >> m >> n;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> x;
			temp.push_back(x);
		}
		matrix.push_back(temp);
		temp.clear();
	}

	vector<int> ret = spiralOrder(matrix);

	cout << "\n Spiral Order: ";
	for (i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";

	cout << "\n\n";
	return 0;
}
