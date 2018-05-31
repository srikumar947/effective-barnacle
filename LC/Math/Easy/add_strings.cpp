/*

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string addStrings(string num1, string num2);

int main()
{
	string num1, num2;
	int x;

	cout << "\n Enter first number: ";
	cin >> x;

	num1 = to_string(x);

	cout << "\n Enter second number: ";
	cin >> x;

	num2 = to_string(x);

	num1 = addStrings(num1, num2);

	cout << "\n The addition is: " << num1 << endl << endl;

	return 0;
}

string addStrings(string num1, string num2) {

	string ret = "";
	int carry = 0, i = 0, j = 0, n = num1.size(), m = num2.size(), temp = 0;

	i = n - 1;
	j = m - 1;

	while ((i >= 0) && (j >= 0)) {
		temp = (num1[i] - '0') + (num2[j] - '0') + carry;

		carry = 0;

		if (temp > 9) {
			carry = temp / 10;
			temp = temp % 10;
		}

		ret += temp + '0';
		i--;
		j--;
	}

	while (i >= 0) {
		temp = (num1[i] - '0') + carry;

		carry = 0;

		if (temp > 9) {
			carry = temp / 10;
			temp = temp % 10;
		}

		ret += temp + '0';
		i--;
	}

	while (j >= 0) {
		temp = (num2[j] - '0') + carry;

		carry = 0;

		if (temp > 9) {
			carry = temp / 10;
			temp = temp % 10;
		}

		ret += temp + '0';
		j--;
	}

	if (carry)
		ret += carry + '0';

	reverse(ret.begin(), ret.end());

	return ret;
}
