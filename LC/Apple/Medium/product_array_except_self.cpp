/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

Input: 1, 2, 3, 4, 5, 6

1. 1, 1, 1, 1, 1, 1
2. 1, 1, 2, 6, 24, 120  (Multiply numbers to the left of number[i])
3. 720, 360, 240, 180, 144, 120 (Multiply numbers to the right of number[i]. The loop start from n-1 and goes to 0.)

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums.size(), 1);    // Step 1
    int i = 0, n = nums.size(), left = nums[0], right = nums[nums.size() - 1];

    for (i = 1; i < n; i++) {
        ret[i] *= left;                 // Step 2
        left *= nums[i];
    }

    for (i = n - 2; i >= 0; i--) {
        ret[i] *= right;                // Step 3
        right *= nums[i];
    }

    return ret;
}

int main() {
    vector<int> nums;
    int n, i, x;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    nums = productExceptSelf(nums);

    cout << "\n Updated Vector: ";
    for (i = 0; i < n; i++)
        cout << nums[i] << " ";

    cout << "\n\n";
    return 0;
}
