/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

string addBinary(string a, string b);
void adder (int a, int b, int temp, int& carry, int& res);

int main()
{
	string a, b;

	cout << "\n Enter number 1: ";
	cin >> a;

	cout << "\n Enter number 2: ";
	cin >> b;

	cout << "\n Addition is: " << addBinary(a, b);

	cout << "\n\n";

	return 0;
}

void adder (int a, int b, int temp, int& carry, int& res) {
	if (a == 1) {
		if (b == 1) {
			if (temp == 1) {
				res = 1;
				carry = 1;
			}
			else {
				res = 0;
				carry = 1;
			}
		}
		else {
			if (temp == 1) {
				res = 0;
				carry = 1;
			}
			else {
				res = 1;
				carry = 0;
			}
		}
	}

	else {
		if (b == 1) {
			if (temp == 1) {
				res = 0;
				carry = 1;
			}
			else {
				res = 1;
				carry = 0;
			}
		}
		else {
			if (temp == 1) {
				res = 1;
				carry = 0;
			}
			else {
				res = 0;
				carry = 0;
			}
		}
	}
}

string addBinary(string a, string b) {
	int i = a.size() - 1, j = b.size() - 1, res = 0, carry = 0, temp = 0;
	string ret = "";

	if ((i == -1) && (j == -1))
		return "";

	if (i == -1)
		return b;

	if (j == -1)
		return a;

	while ((i >= 0) && (j >= 0)) {
		adder (a[i] - '0', b[j] - '0', carry, temp, res);
		carry = temp;
		ret += res + '0';
		i--;
		j--;
	}

	while (i >= 0) {
		adder (a[i] - '0', 0, carry, temp, res);
		carry = temp;
		ret += res + '0';
		i--;
	}

	while (j >= 0) {
		adder (0, b[j] - '0', carry, temp, res);
		carry = temp;
		ret += res + '0';
		j--;
	}

	if (carry) {
		ret += carry + '0';
	}

	reverse(ret.begin(), ret.end());

	return ret;
}
