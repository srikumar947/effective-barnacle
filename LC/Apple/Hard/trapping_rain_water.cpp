/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
The elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water are being trapped.
For pictorial description - https://leetcode.com/problems/trapping-rain-water/description/

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

0 1 0 2 1 0 1 3 2 1 2 1
*/

#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    if (height.size() < 1)
        return 0;

    int left = 0, right = height.size() - 1, safe = 0, lower, ret = 0;

    while (left < right) {
        lower = height[height[left] < height[right] ? left++ : right--];
        safe = max(safe, lower);
        ret += safe - lower;
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

    x = trap(nums);

    cout << "\n Units Trapped: " << x;

    cout << "\n\n";
    return 0;
}
