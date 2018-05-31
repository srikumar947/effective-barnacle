/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	int i = 0, j = 0;
	for (i = 0, j = s.size() - 1; i <= j; i++, j--)
		if (s[i] != s[j])
			return false;
	return true;
}

int countSubstrings(string s) {
	if (s.size() < 1)
        return 0;

	int ret = s.size(), i = 0, j = 0;
	for (i = 0; i < s.size(); i++)
		for (j = i + 1; j < s.size(); j++)
			if (isPalindrome(s.substr(i, j - i + 1)))
				ret += 1;
	return ret;
}

int main() {
	string s;

	cout << "\n Enter string: ";
	cin >> s;

	cout << "\n Number of palindromic substrings: " << countSubstrings(s);

	cout << "\n\n";

	return 0;
}
