/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start], l = start + 1, r = end;
    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot)
            swap(nums[l++], nums[r--]);
        if (nums[l] >= pivot)
            l++;
        if (nums[r] <= pivot)
            r--;
    }
    swap(nums[start], nums[r]);
    return r;
}

int findKthLargest(vector<int>& nums, int k) {
    int start = 0, end = nums.size() - 1, pos = 0;
    while(true) {
        pos = partition(nums, start, end);
        if (pos == k - 1)
            return nums[pos];

        if (pos > k - 1)
            end = pos - 1;
        else
            start = pos + 1;
    }
}

int main() {
    vector<int> nums;
    int i, x, n;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    cout << "\n Enter k: ";
    cin >> n;

    cout << "\n Kth Largest Number: " << findKthLargest(nums, n);

    cout << "\n\n";
    return 0;
}
