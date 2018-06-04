/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
	unordered_map<char, int> map;
	for (auto c : s)
		if (map.find(c) != map.end())
			map[c] += 1;
		else
			map[c] = 1;
	for (int i = 0; i < s.size(); i++)
		if (map[s[i]] == 1)
			return i;
	return -1;
}

int main () {
	string s;

	cout << "\n Enter string: ";
	cin >> s;

	cout << "\n First Unique Character: " << firstUniqChar(s);

	cout << "\n\n";
	return 0;
}
