/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

4 3 2 7 8 2 3 1
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
	if (nums.size() < 1)
		return vector<int>(0);

	int i, n = nums.size();
	vector<int> ret;

	for (i = 0; i < n; i++) {
		int t = abs(nums[i]) - 1;
		nums[t] = nums[t] > 0 ? -nums[t] : nums[t];
	}

	for (i = 0; i < n; i++)
		if (nums[i] > 0)
			ret.push_back(i + 1);
	return ret;
}

int main () {
	vector<int> nums;
	int i, x, n;

	cout << "\n Enter n: ";
	cin >> n;


	cout << "\n Enter values: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	vector<int> ret = findDisappearedNumbers(nums);

	cout << "\n Missing Numbers: ";
	for (i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";

	cout << "\n\n";
	return 0;
}
