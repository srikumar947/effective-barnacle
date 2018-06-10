/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
	stack<int> st;
	int n = s.size(), i, j, ret = 0, sign = 1;

	for (i = 0; i < n; i++) {
		if (isdigit(s[i])) {
			int temp = s[i] - '0';
			while (i + 1 < n && isdigit(s[i + 1]))
				temp = (temp * 10) + (s[++i] - '0');
			ret += temp * sign;
		}
		else if (s[i] == '+')
			sign = 1;
		else if (s[i] == '-')
			sign = -1;
		else if (s[i] == '(') {
			st.push(ret);
			st.push(sign);
			ret = 0;
			sign = 1;
		}
		else if (s[i] == ')') {
			ret *= st.top();
			st.pop();
			ret += st.top();
			st.pop();
		}
	}
	return ret;
}

int main () {
	string x;

	// If you want to include spaces in the input string, use getline or store as string instead of cin.
	cout << "\n Enter expression: ";
	cin >> x;

	cout << "\n Answer: " << calculate(x);

	cout << "\n\n";
	return 0;
}
