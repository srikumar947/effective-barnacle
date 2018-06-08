/*
Given a circular array of integers with relative indices (value at index points to another element), find if a complete cycle exists.
A complete cycle is one where all elements are part of the cycle and it starts/ends from/on index 0.

Input: 1, 1, 1, 1
Output: true

Input: 2, 1, 3, 4
Output: false

Input: 1, 1, 1, -3
Output: true

Input: -1, -1, -1, -1
Output: true
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isCompleteCycle(vector<int>& nums) {
	if (nums.size() < 1)
		return false;

	int i = 0, j = 0, next_pos, n = nums.size(), count = 0;

	unordered_map<int, int> visited;

	while (count < n) {
		if (visited.find(i) != visited.end())
			return false;

		visited[i] = 1;
		count += 1;
		next_pos = nums[i] % n;
		i += next_pos;

		if (i >= n)
			i = i - n;
		else if (i < 0)
			i = n + i;
	}

	for (j = 0; j < n; j++)
		if (!visited[j])
			return false;

	if (i == 0)
		return true;
	else
		return false;
}

int main() {
	int i, x, n;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter elements: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Complete Cycle: " << isCompleteCycle(nums);

	cout << "\n\n";
	return 0;
}
