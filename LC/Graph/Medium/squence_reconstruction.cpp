/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true
UPDATE (2017/1/8):
The seqs parameter had been changed to a list of list of strings (instead of a 2d array of strings). Please reload the code definition to get the latest changes.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    int i = 0, n = org.size(), m = seqs.size(), match = org.size() - 1, flag = 0;
    vector<int> pos(n + 1);
    vector<int> visited(n + 1, 0);

    if (m < 1)
        return false;

    for (i = 0; i < n; i++)
        pos[org[i]] = i;

    for (auto s : seqs) {
        for (i = 0; i < s.size(); i++) {
            flag = true;
            if (s[i] < 1 || s[i] > n)
                return false;
            if (i != 0) {
                if (pos[s[i - 1]] >= pos[s[i]])
                    return false;
                if (visited[s[i - 1]] == 0 && pos[s[i - 1]] + 1 == pos[s[i]]) {
                    visited[s[i - 1]] = 1;
                    match -= 1;
                }
            }
        }
    }

    return match == 0 && flag;
}

int main() {
    vector<vector<int>> seqs = {{5,2,6,3},{4,1,5,2}};
    vector<int> org = {4,1,5,2,6,3};

    cout << "\n Sequence can be reconstructed: " << sequenceReconstruction(org, seqs);

    cout << "\n\n";
    return 0;
}
