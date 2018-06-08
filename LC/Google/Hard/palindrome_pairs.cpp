/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPalindrome(string a) {
	for (int i = 0, j = a.size() - 1; i < j; i++, j--)
		if (a[i] != a[j])
			return false;
	return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
	int i, j, n = words.size();
	unordered_map<string, int> map;
	vector<vector<int>> ret;

	if (words.size() < 2)
		return ret;

	for (i = 0; i < n; i++)
		map[words[i]] = i;

	for (i = 0; i < n; i++) {
		for (j = 0; j <= words[i].size(); j++) {
			string s1 = words[i].substr(0, j);
			string s2 = words[i].substr(j);

			if (isPalindrome(s1)) {
				string s2r = s2;
				reverse(s2r.begin(), s2r.end());
				if (map.find(s2r) != map.end() && map[s2r] != i)
					ret.push_back(vector<int>{map[s2r], i});
			}

			if (isPalindrome(s2)) {
				string s1r = s1;
				reverse(s1r.begin(), s1r.end());
				if (map.find(s1r) != map.end() && map[s1r] != i && s2.size() != 0)
					ret.push_back(vector<int>{i, map[s1r]});
			}
		}
	}
	return ret;
}

int main () {
	int i, n;
	string x;
	vector<string> words;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter the words: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		words.push_back(x);
	}

	vector<vector<int>> ret = palindromePairs(words);

	cout << "\n Palindromes are - \n";
	for (i = 0; i < ret.size(); i++) {
		for (n = 0; n < ret[i].size(); n++) {
			cout << ret[i][n] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";
	return 0;
}
