/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of unique strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

Example 1:

Input: ["tars","rats","arts","star"]
Output: 2
Note:

A.length <= 2000
A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool sameGroup(string a, string b) {
    int ret = 0;
    for (int i = 0; i < a.size() && ret < 3; i++)
        if (a[i] != b[i])
            ret += 1;
    return ret == 2;
}

void dfs(int node, vector<string>& A) {
    string temp = A[node];
    A[node] = "";
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != "" && sameGroup(temp, A[i]))
            dfs(i, A);
    }
}

int numSimilarGroups(vector<string>& A) {
    int ret = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != "") {
            ret += 1;
            dfs(i, A);
        }
    }
    return ret;
}

int main() {
    vector<string> words;
    string temp;
    int i, m;

    cout << "\n Enter number of words: ";
    cin >> m;

    cout << "\n Enter the words: ";
    for (i = 0; i < m; i++) {
        cin >> temp;
        words.push_back(temp);
    }

    int ret = numSimilarGroups(words);

    cout << "\n Number of groups: " << ret;

    cout << "\n\n";
    return 0;
}
