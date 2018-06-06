/*
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
Note:
The peak can be either the first or last element. Assume that the elements on either ends of the array are INT_MIN.
Your solution should be in logarithmic complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	if (nums.size() < 1)
		return -1;

	int start = 0, end = nums.size() - 1, mid;

	while (true) {
		if (start == end)
			return start;

		mid = (start + end) / 2;

		if (nums[mid] > nums[mid + 1])
			end = mid;
		else
			start = mid + 1;
	}
}

int main () {
	int i, n, x;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter values: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Peak position: " << findPeakElement(nums);

	cout << "\n\n";
	return 0;
}
