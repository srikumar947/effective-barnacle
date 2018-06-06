/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void generateStrings(vector<string>& ret, unordered_set<string>& set, unordered_map<char, vector<char>>& map, string digits) {
	for (int i = 0; i <= digits.size() - 1; i++) {
		for (auto c : map[digits[i]]) {
			digits[i] = c;
			generateStrings(ret, set, map, digits);
		}
	}

	if (set.find(digits) == set.end()) {
		set.insert(digits);
		ret.push_back(digits);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> ret;
	unordered_set<string> set;
	unordered_map<char, vector<char>> map;

	if (digits.size() < 1)
		return ret;

	map['2'] = {'a', 'b', 'c'};
	map['3'] = {'d', 'e', 'f'};
	map['4'] = {'g', 'h', 'i'};
	map['5'] = {'j', 'k', 'l'};
	map['6'] = {'m', 'n', 'o'};
	map['7'] = {'p', 'q', 'r', 's'};
	map['8'] = {'t', 'u', 'v'};
	map['9'] = {'w', 'x', 'y', 'z'};

	generateStrings(ret, set, map, digits);

	return ret;
}

int main () {
	string digits;

	cout << "\n Enter string: ";
	cin >> digits;

	vector<string> ret = letterCombinations(digits);

	cout << "\n All possible combinations - \n";
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	cout << "\n\n";
	return 0;
}
