/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool wordChecker(string s, vector<string>& wordDict, unordered_map<int, bool>& map, int start) {
	if (start == s.size())
		return true;

	if (map.find(start) != map.end())
		return map[start];

	for (int i = 1; i <= s.size() - start; i++) {
		if ((find(wordDict.begin(), wordDict.end(), s.substr(start, i)) != wordDict.end()) && wordChecker(s, wordDict, map, start + i)) {
			map[start] = true;
			return true;
		}
	}

	map[start] = false;
	return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
	unordered_map<int, bool> map;
	return wordChecker(s, wordDict, map, 0);
}

int main () {
	string s, x;
	int i, n;
	vector<string> wordDict;

	cout << "\n Enter string: ";
	cin >> s;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter dictionary words: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		wordDict.push_back(x);
	}

	cout << "\n String can be constructed: " << wordBreak(s, wordDict);

	cout << "\n\n";
	return 0;
}
