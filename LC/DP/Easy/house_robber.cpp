/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int rob(vector<int>& nums) {
	if (nums.size() < 1)
		return 0;
	int *opt = new int[nums.size()];
	int last = nums.size() - 1;
	opt[last] = nums[last];
	opt[last - 1] = max(opt[last], nums[last - 1]);
	for (int i = last - 2; i >=0; i--)
		opt[i] = max(nums[i] + opt[i + 2], opt[i + 1]);
	return opt[0];
}

int main() {
	int n, x;
	vector<int> nums;

	cout << "\n Enter number of houses: ";
	cin >> n;

	cout << "\n Enter the values: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Maximum value: " << rob(nums);

	cout << "\n\n";

	return 0;
}
