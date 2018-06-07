/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

2147483646 -2147483647 0 2 2147483644 -2147483645 2147483645
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	if (nums.size() <= 1)
		return nums.size();

	int i, y, ret = 0;
	unordered_set<int> set(nums.begin(), nums.end());

	for (auto x : nums) {
		if (set.find(x - 1) == set.end()) {
			y = x + 1;
			while (set.find(y) != set.end())
				y += 1;
			ret = max(ret, y - x);
		}
	}
	return ret;
}

int main () {
	int i, n, x;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter elements: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n The length of longest consecutive sequence is " << longestConsecutive(nums);

	cout << "\n\n";
	return 0;
}
