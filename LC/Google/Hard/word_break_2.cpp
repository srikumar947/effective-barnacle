/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> wordBuilder(string s, unordered_map<int, vector<string>>& map, vector<string>& wordDict, int start) {
	if (map.find(start) != map.end())
		return map[start];

	vector<string> ret;

	if (start == s.size())
		ret.push_back("");

	for (int i = 1; i <= s.size() - start; i++) {
		if (find(wordDict.begin(), wordDict.end(), s.substr(start, i)) != wordDict.end()) {
			vector<string> temp = wordBuilder(s, map, wordDict, start + i);
			for (string t : temp)
				ret.push_back(s.substr(start, i) + (t == "" ? "" : " ") + t);
		}
	}

	map[start] = ret;
	return ret;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
	unordered_map<int, vector<string>> map;
	return wordBuilder(s, map, wordDict, 0);
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
	vector<string> ret = wordBreak(s, wordDict);;

	cout << "\n Sentences constructed - \n";
	for (i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	cout << "\n\n";
	return 0;
}
