/*
A string consists of ‘0’, ‘1’ and ‘?’.
The question mark can be either ‘0’ or ‘1’.
Find all possible combinations for a string.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void generateString(vector<string>& ret, string s, unordered_set<string>& set) {
	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			flag = 1;
			s[i] = '0';
			generateString(ret, s, set);
			s[i] = '1';
			generateString(ret, s, set);
		}
	}

	if (flag == 0 && set.find(s) == set.end()) {
		ret.push_back(s);
		set.insert(s);
	}
}

vector<string> findCombinations(string s) {
	if (s.size() < 1)
		return vector<string>(0);

	vector<string> ret;
	unordered_set<string> set;

	generateString(ret, s, set);

	return ret;
}

int main () {
	string s;

	cout << "\n Enter string: ";
	cin >> s;

	vector<string> ret = findCombinations(s);

	cout << "\n All possible combinations - \n";
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	cout << "\n\n";
	return 0;
}
