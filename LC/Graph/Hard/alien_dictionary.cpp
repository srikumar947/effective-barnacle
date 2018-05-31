/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
]

Output: ""

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, string& ret) {
    visited[node] = 1;
    for (auto g : graph[node]) {
        if (visited[g] == 1)
            return false;
        if (visited[g] == 0 && !dfs(g, graph, visited, ret))
            return false;
    }

    visited[node] = 2;
    ret += (char)(node + 'a');
    return true;
}

string alienOrder(vector<string>& words) {
    string ret;
    int i, j;
    vector<int> visited(26, -1);
    vector<vector<int>> graph(26);

    for (i = 0; i < words.size(); i++) {
        for (j = 0; j < words[i].size(); j++)
            visited[words[i][j] - 'a'] = 0;

        if (i != 0) {
            string w1 = words[i - 1], w2 = words[i];
            for (j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
            }
        }
    }

    for (i = 0; i < 26; i++)
        if (visited[i] == 0 && !dfs(i, graph, visited, ret))
            return "";

    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    vector<string> words;
    string ret, temp;
    int i, m;

    cout << "\n Enter number of words: ";
    cin >> m;

    cout << "\n Enter the words: ";
    for (i = 0; i < m; i++) {
        cin >> temp;
        words.push_back(temp);
    }

    ret = alienOrder(words);

    cout << "\n Alien Order: " << ret;

    cout << "\n\n";
    return 0;
}
