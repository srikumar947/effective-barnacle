/*
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:

Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Sort and then swap. O(nlogn)
void wiggleSort2(vector<int>& nums) {
    if (nums.size() < 2)
        return;
    int n = nums.size(), i = 0;
    sort(nums.begin(), nums.end());
    for (i = 1; i < n - 1; i += 2)
        swap (nums[i], nums[i + 1]);
}

// Swap without sorting. O(n)
void wiggleSort(vector<int>& nums) {
    if (nums.size() < 2)
        return;

    int n = nums.size(), i = 0;
    for (i = 1; i < n; i++) {
        if (i % 2 == 1) {
            if (nums[i - 1] > nums[i])
                swap(nums[i - 1], nums[i]);
        }
        else {
            if (nums[i - 1] < nums[i])
                swap(nums[i - 1], nums[i]);
        }
    }
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

    wiggleSort(nums);

    cout << "\n Wiggle Sorted: ";
    for (i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << "\n\n";
}
