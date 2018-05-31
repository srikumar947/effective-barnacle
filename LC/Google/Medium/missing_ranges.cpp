/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string add_string(int start, int end) {
    if (start == end)
        return to_string(start);

    return to_string(start) + "->" + to_string(end);
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ret;
    long int previous = (long)lower-1;
    long int current;
    if (nums.size() < 1) {
        ret.push_back(add_string(lower,upper));
        return ret;
    }

    for (int i = 0; i <= nums.size(); i++) {
        if (i == nums.size())
            current = (long)upper + 1;
        else
            current = (long)nums[i];

        if (current - previous >= 2)
            ret.push_back(add_string(previous + 1, current - 1));

        previous = current;
    }

    return ret;
}

int main () {
    vector<int> v;
    vector<string> s;
    int n, i, x;

    cout << "\n Enter number of elements: ";
    cin >> n;

    cout << "\n Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    cout << "\n Enter (lower, upper): ";
    cin >> n >> x;

    s = findMissingRanges(v, n, x);

    cout << "\n Missing Ranges - ";

    for (i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    cout << "\n\n";
}
