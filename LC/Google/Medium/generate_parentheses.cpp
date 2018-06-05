/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void genPair(vector<string>& ret, string s, int openToAdd, int closeToAdd) {
	if (openToAdd == 0 && closeToAdd == 0)
		ret.push_back(s);

	else {
		if (openToAdd > 0)
			genPair(ret, s + "(", openToAdd - 1, closeToAdd + 1);
		if (closeToAdd > 0)
			genPair(ret, s + ")", openToAdd, closeToAdd - 1);
	}
}

vector<string> generateParenthesis(int n) {
	if (n < 1)
		return vector<string>(0);
	vector<string> ret;
	genPair(ret, "", n, 0);
	return ret;
}

int main () {
	int i, n;

	cout << "\n Enter n: ";
	cin >> n;

	vector<string> ret = generateParenthesis(n);

	cout << "\n All valid sequences - \n";
	for (i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	cout << "\n\n";
	return 0;
}
