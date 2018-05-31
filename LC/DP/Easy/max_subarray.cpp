/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

opt[i] = maximum value of subarray at that index.
opt[0] = nums[0] - Base case
For all others,
opt[i] is either opt[i - 1] + nums[i] or just nums[i] (whicever is greater).
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int *opt = new int[nums.size()];
	int ret = nums[0];
	opt[0] = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		opt[i] = max(opt[i - 1] + nums[i], nums[i]);
		if (ret < opt[i])
			ret = opt[i];
	}

	return ret;
}

int main() {
	int n, x;
	vector<int> nums;

	cout << "\n Enter number of elements: ";
	cin >> n;

	cout << "\n Enter the values: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Maximum value: " << maxSubArray(nums);

	cout << "\n\n";

	return 0;
}
