/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

26 78 27 100 33 67 90 23 66 5 38 7 35 23 52 22 83 51 98 69 81 32 78 28 94 13 2 97 3 76 99 51 9 21 84 66 65 36 100 41
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void merge(vector<int>& nums, vector<int>& ret, vector<int>& pos, int start, int mid, int end) {
	int i = start, j = mid, count = 0;
	vector<int> temp;

	while (i < mid || j <= end) {
		if ((j > end) || (i < mid && nums[pos[i]] <= nums[pos[j]])) {
			temp.push_back(pos[i]);
			ret[pos[i++]] += count;
		}
		else {
			temp.push_back(pos[j++]);
			count += 1;
		}
	}

	for (i = 0, j = start; i < temp.size(); i++)
		pos[j++] = temp[i];
}

void mergeSort(vector<int>& nums, vector<int>& ret, vector<int>& pos, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(nums, ret, pos, start, mid);
		mergeSort(nums, ret, pos, mid + 1, end);
		merge(nums, ret, pos, start, mid + 1, end);
	}
}

vector<int> countSmaller(vector<int>& nums) {
	vector<int> ret(nums.size(), 0);
	vector<int> pos(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++)
		pos[i] = i;
	mergeSort(nums, ret, pos, 0, nums.size() - 1);
	return ret;
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

	vector<int> ret = countSmaller(nums);

	cout << "\n Counts: ";
	for (i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";

	cout << "\n\n";
	return 0;
}
