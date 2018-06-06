/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findMaximumXOR(vector<int>& nums) {
	if (nums.size() < 1)
		return -1;

	unordered_set<int> set;
	int mask = 0, max = 0, i, temp;

	for (i = 31; i >= 0; i--) {
		set.clear();
		mask = mask | (1 << i);

		for (auto n : nums)
			set.insert(n & mask);

		temp = max | (1 << i);

		for (auto s : set)
			if (set.count(temp ^ s) != 0) {
				max = temp;
				break;
			}
	}

	return max;
}

int main () {
	int i, n, x;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter numbers: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Max XOR: " << findMaximumXOR(nums);

	cout << "\n\n";
	return 0;
}
