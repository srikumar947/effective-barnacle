/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"
Example 2:

Input: "cbacdcbc"
Output: "acdb"
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string removeDuplicateLetters(string s) {
	vector<int> count(26, 0);
	vector<bool> added(26, false);

	string ret = "";

	for (auto c : s)
		count[c - 'a'] += 1;

	for (auto c : s) {
		count[c - 'a'] -= 1;

		if (added[c - 'a'])
			continue;

		while (!ret.empty() && ret.back() > c && count[ret.back() - 'a'] > 0) {
			added[ret.back() - 'a'] = false;
			ret.pop_back();
		}

		ret.push_back(c);
		added[c - 'a'] = true;
	}

	return ret;
}

int main () {
	string s;

	cout << "\n Enter string: ";
	cin >> s;

	cout << "\n Modified string: " << removeDuplicateLetters(s);

	cout << "\n\n";
	return 0;
}
