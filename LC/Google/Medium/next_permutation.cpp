/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void nextPermutation(vector<int>& nums) {
	if (nums.size() < 1)
		return;

	int i = nums.size() - 1, j, k = nums.size() - 1;

	while (i > 0 && nums[i - 1] >= nums[i])				// Find the first number that is smaller than the next element
		i -= 1;

	for (j = i; j < k; j++, k--)						// Sort the numbers in ascending order to the right of the element found
		swap(nums[j], nums[k]);

	if (i > 0) {										// If i is not the first element (we still haven't got the next permutation), find a number
		k = i;											// that is greater than the element to the left of i (loop over the ascending order numbers)
		i -= 1;
		while (nums[k] <= nums[i])
			k += 1;
		swap(nums[k], nums[i]);
	}
}

/*
A run for 1, 4, 3, 2 -

Step 1: i = 1
Step 2: Array = [1, 2, 3, 4]
Step 3: Array = [2, 1, 3, 4]

*/

int main () {
	int i, n, x;
	vector<int> temp;

	cout << "\n Enter n: ";
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> x;
		temp.push_back(x);
	}

	nextPermutation(temp);

	cout << "\n Next Permutation: ";
	for (i = 0; i < temp.size(); i++)
		cout << temp[i] << " ";

	cout << "\n\n";
	return 0;
}
