/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

bool dp(int i, int j, string s, string p, vector<vector<int>>& map) {
	if (map[i][j] != -1)						// If map entry is already present, return it
		return map[i][j] == 1;

	if (j == p.size()) {						// If we've reached end of pattern
		if (i == s.size()) {					// If we've reached end of string as well, we've matched all characters
			map[i][j] = 1;
			return true;
		}
		else {									// Else, we have unmatched characters
			map[i][j] = 0;
			return false;
		}
	}

	else {
		bool temp, first = (i < s.size() && (s[i] == p[j] || p[j] == '.'));					// Check if first character matches

		if (j + 1 < p.size() && p[j + 1] == '*')											// See if the next character of pattern is *
			temp = (dp(i, j + 2, s, p, map) || (first && dp(i + 1, j, s, p, map)));			// Check if discarding the first two characters of pattern results in string match. If not, check if first is true and the substring from second character of s is matched by pattern.
		else
			temp = (first && dp(i + 1, j + 1, s, p, map));									// If char is not *, match substrings of s and p from next char

		map[i][j] = (temp == true) ? 1 : 0;													// Store result in map

		return temp;
	}
}

bool isMatch(string s, string p) {
	vector<vector<int>> map(s.size() + 1, vector<int>(p.size() + 1, -1));
	return dp(0, 0, s, p, map);
}

int main () {
	string s, p;

	cout << "\n Enter (s, p): ";
	cin >> s >> p;

	cout << "\n The string can be matched: " << isMatch(s, p) << "\n";

	cout << "\n\n";
	return 0;
}
