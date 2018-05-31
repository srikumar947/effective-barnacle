/*

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// 13 ms
vector<int> partitionLabels(string S) {
	vector<int> ret;
	unordered_map <char, int> map;

	int i = 0, j = 0, pos = 0, previous = -1;
	char x;
	for (i = 0; i < S.size(); i++) {
		x = S[i];
		pos = i;

		if (map[x] != 1) {
			for (j = S.size() - 1; j >= i + 1 ; j--) {
				if (S[j] == x) {
					pos = j;
					break;
				}
			}

			if (i < previous && pos < previous) {
				continue;
			}

			if (i < previous && pos > previous) {
				ret.erase(ret.end() - 1);
			}

			previous = pos;
			ret.push_back(pos + 1);
		}
		map[x] = 1;
	}

	for(i = ret.size() - 1; i > 0; i--)
		ret[i] = ret[i] - ret[i - 1];

	return ret;
}

// 7ms
vector<int> partitionLabels2(string S) {
	vector<int> ret, last(26, 0);
	int i, pos = 0, start = 0;

	for (i = 0; i < S.size(); i++)
		last[S[i] - 'a'] = i;

	for (i = 0; i < S.size(); i ++) {
		pos = max(pos, last[S[i] - 'a']);
		if (pos == i) {
			ret.push_back(pos - start + 1);
			start = pos + 1;
		}
	}
	return ret;
}

int findEnd(string S, int start, int end, unordered_map <char, int> map) {
    int newPos = -1;
    for (int i = start; i <= end; i++)
        newPos = max(newPos, map[S[i]]);

    if (newPos > end)
        newPos = findEnd(S, end, newPos, map);

    return newPos;
}

vector<int> partitionLabels3(string S) {
	vector<int> ret;
    unordered_map <char, int> map;
	int i, j, pos = 0, newPos = 0;

	for (i = 0; i < S.size(); i++)
		map[S[i]] = i;

	for (i = 0; i < S.size();) {
		pos = map[S[i]];

        newPos = findEnd(S, i, pos, map);

		ret.push_back(newPos - i + 1);
		i = newPos + 1;
	}
	return ret;
}

int main() {
	string S;
	vector<int> g;

	cout << "\n Enter string: ";
	cin >> S;

	g = partitionLabels3(S);

	cout << "\n Partition is = ";

	for (int i = 0; i < g.size(); i++)
		cout << " " << g[i];

	cout << "\n\n";

	return 0;
}
