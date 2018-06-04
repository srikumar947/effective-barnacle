/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <iostream>
#include <stack>

using namespace std;

int picked;

bool isValid(string s) {
	if (s.size() < 1)
		return true;

	stack<char> st;

	for (auto c : s) {
		if (c == '[' || c == '{' || c == '(')
			st.push(c);
		else {
			if (st.empty())
				return false;
			char t = st.top();
			st.pop();
			if (c == '}' && t != '{')
				return false;
			else if (c == ']' && t != '[')
				return false;
			else if (c == ')' && t != '(')
				return false;
		}
	}
	if (st.empty())
		return true;
	return false;
}

int main () {
	string s;

	cout << "\n Enter string: ";
	cin >> s;

	cout << "\n Valid Parentheses: " << isValid(s);

	cout << "\n\n";
	return 0;
}
