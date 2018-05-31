/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

Your NumArray object will be instantiated and called as such:
NumArray obj = new NumArray(nums);
int param_1 = obj.sumRange(i,j);

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class NumArray {
public:
	int* ret;
	int* copy;
	int n;

    NumArray(vector<int> nums) {
		n = nums.size();
		ret = new int[n];
		copy = new int[n];
		for (int i = 0; i < nums.size(); i++)
			copy[i] = nums[i];
		for (int i = 1; i < nums.size(); i++)
			nums[i] += nums[i - 1];
		for (int i = 0; i < nums.size(); i++)
			ret[i] = nums[i];
    }

    int sumRange(int i, int j) {
		if ((i < 0) || (i > j) || (j >= n))
			return 0;
		if(i == j)
			return copy[i];
		if (i == 0)
			return ret[j];
		return ret[j] - ret[i - 1];
    }
};

int main() {
	int n, x, i, j;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter the values: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}

	cout << "\n Enter i, j: ";
	cin >> i >> j;

	NumArray obj(nums);

	cout << "\n Value of subarray: " << obj.sumRange(i, j);

	cout << "\n\n";

	return 0;
}
