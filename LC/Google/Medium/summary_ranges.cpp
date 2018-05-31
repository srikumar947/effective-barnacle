/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

[-2147483648,-2147483647,2147483647]

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_string(long start, long end) {
    if (start == end)
        return to_string(start);
    return to_string(start) + "->" + to_string(end);
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    if (nums.size() < 1)
        return ret;

    if (nums.size() == 1) {
        ret.push_back(to_string(nums[0]));
        return ret;
    }


    long i = 0, n = nums.size(), start = nums[0], end = -1, res;

    for (i = 1; i < n; i++) {
        res = nums[i] - nums[i - 1];
        if (abs(res) != 1) {
            end = nums[i - 1];
            ret.push_back(get_string(start, end));
            start = nums[i];
        }
        if (i == n - 1) {
            end = nums[i];
            ret.push_back(get_string(start, end));
        }
    }
    return ret;
}

int main () {
    vector<int> nums;
    int i, x, n;

    cout << "\n Enter number of elements: ";
    cin >> n;

    cout << "\n Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    vector<string> s = summaryRanges(nums);

    cout << "\n Summary: ";
    for (i = 0; i < s.size(); i++)
        cout << s[i] << " ";

    cout << "\n\n";
}
