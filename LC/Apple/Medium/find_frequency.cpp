/*
Given an unsorted array of n integers which contains integers from 1 to n. Some elements can be repeated multiple times and some other elements can be absent from the array. Count frequency of all elements that are present and print the missing elements.
Space complexity should be O(1). Ignore the return vector for space complexity.

Input: arr[] = {2, 3, 3, 2, 5}
Output: Below are frequencies of all elements
        1 -> 0
        2 -> 2
        3 -> 2
        4 -> 0
        5 -> 1

Input: arr[] = {4, 4, 4, 4}
Output: Below are frequencies of all elements
        1 -> 0
        2 -> 0
        3 -> 0
        4 -> 4
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> countFrequencies(vector<int>& nums) {
    vector<int> ret;
    if (nums.size() < 1)
        return ret;

    for (int i = 0; i < nums.size(); i++)
        nums[i] -= 1;

    for (int i = 0; i < nums.size(); i++)
        nums[nums[i] % nums.size()] += nums.size();

    for (int i = 0; i < nums.size(); i++)
        ret.push_back(nums[i]/nums.size());

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

    vector<int> ret = countFrequencies(nums);

    cout << "\n Frequencies are - ";
    for (i = 0; i < ret.size(); i++)
        cout << "\n Node " << i + 1 << ": " << ret[i];

    cout << "\n\n";
    return 0;
}
