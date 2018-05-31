/*
A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation:
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
Note:
N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of A is an integer within the range [0, N-1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int arrayNesting(vector<int>& nums) {
    int ret = 0, i = 0, n = nums.size(), count = 0, k = 0;
    unordered_map<int, int> map;

    for (i = 0; i < n; i++) {
        count = 0;
        k = i;
        while(map.find(k) == map.end()) {
            map[k] = 1;
            k = nums[k];
            count += 1;
        }
        ret = max(ret, count);
    }
    return ret;
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

    cout << "\n Longest set size: " << arrayNesting(nums);

    cout << "\n\n";
    return 0;
}
