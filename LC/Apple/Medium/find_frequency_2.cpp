/*
Given an sorted array of positive integers, count number of occurrences for each element in the array. Assume all elements in the array are less than some constant M.

Do this without traversing the complete array. i.e. expected time complexity is less than O(n).

Examples:

Input: arr[] = [1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10]
Output:
Element 1 occurs 3 times
Element 2 occurs 1 times
Element 3 occurs 2 times
Element 5 occurs 2 times
Element 8 occurs 3 times
Element 9 occurs 2 times
Element 10 occurs 1 times
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void find(vector<int>& nums, int start, int end, unordered_map<int, int>& ret) {
    if (nums[start] == nums[end]) {
        if (ret.find(nums[start]) != ret.end())
            ret[nums[start]] += end - start + 1;
        else
            ret[nums[start]] = end - start + 1;
    }


    else {
        int mid = (start + end) / 2;
        find(nums, start, mid, ret);
        find(nums, mid + 1, end, ret);
    }
}

unordered_map<int, int> countFrequencies(vector<int>& nums) {
    unordered_map<int, int> ret;

    if (nums.size() < 1)
        return ret;

    find(nums, 0, nums.size() - 1, ret);

    return ret;
}

int main() {
    vector<int> nums;
    int i, n, x;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    unordered_map<int, int> ret = countFrequencies(nums);

    cout << "\n Frequencies are - ";
    for (auto it = ret.begin(); it != ret.end(); it++)
        cout << "\n Node " << it->first << ": " << it->second;

    cout << "\n\n";
    return 0;
}
