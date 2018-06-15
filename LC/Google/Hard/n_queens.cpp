/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

#include <iostream>
#include <vector>

using namespace std;

bool isValid(int row, int col, vector<string> temp) {
	for (int i = 0; i < row; i++) {
		string t = temp[i];
		int j = t.find("Q");
		if ((j == col) || ((row - i) == (abs(j - col))))
			return false;
	}
	return true;
}

void generateQueens(int row, int n, vector<string>& temp, vector<vector<string>>& ret) {
	if (row == n) {
		ret.push_back(temp);
		return;
	}

	for (int j = 0; j < n; j++) {
		if (isValid(row, j, temp)) {
			temp[row][j] = 'Q';
			generateQueens(row + 1, n, temp, ret);
			temp[row][j] = '.';
		}
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<string> temp(n, string(n, '.'));
	vector<vector<string>> ret;

	if (n < 1)
		return ret;

	generateQueens(0, n, temp, ret);
	return ret;
}

int main () {
	int n;

	cout << "\n Enter n: ";
	cin >> n;

	vector<vector<string>> ret = solveNQueens(n);

	cout << "\n All possible combinations - \n";
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j] << "\n";
		}
		cout << "\n";
	}

	cout << ret.size();
	cout << "\n\n";
	return 0;
}
