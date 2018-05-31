/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:

Input: nums = [-2,0,1,3], and target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
Follow up: Could you solve it in O(n2) runtime?
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3)
        return 0;

    sort(nums.begin(), nums.end());
    int ret = 0, i = 0, j = 0, k = 0;

    for (i = 0; i < nums.size() - 2; i++) {
        for (j = i + 1, k = nums.size() - 1; j < k; ) {
            if (nums[i] + nums[j] + nums[k] < target) {
                ret += k - j;
                j += 1;
            }
            else
                k -= 1;
        }
    }
    return ret;
}

int main () {
    vector<int> nums;

    int i, x, n, t;

    cout << "\n Enter number of elements: ";
    cin >> n;

    cout << "\n Enter the numbers: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    cout << "\n Enter Target: ";
    cin >> t;

    cout << "\n Number of Triplets: " << threeSumSmaller(nums, t);

    cout << "\n\n";
}
