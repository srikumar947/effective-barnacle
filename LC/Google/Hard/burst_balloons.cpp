/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the balloon you burst is balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

Input: [1, 2, 3, 4]
Output: 40

Input: [1, 2, 3]
Output: 12

1 1 2 3 1

0 0 2 9 12
0 0 0 6 9
0 0 0 0 6
0 0 0 0 0
0 0 0 0 0
*/

#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& nums) {
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	int n = nums.size(), i, k, left, right;
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (k = 2; k < n; k++) {
		for (left = 0; left < n - k; left++) {
			right = left + k;
			for (i = left + 1; i < right; i++) {
				dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + (dp[left][i] + dp[i][right]));
			}
		}
	}

	return dp[0][n - 1];
}

int main () {
	int i, n, x;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter the elements: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Max Coins: " << maxCoins(nums);

	cout << "\n\n";
	return 0;
}
