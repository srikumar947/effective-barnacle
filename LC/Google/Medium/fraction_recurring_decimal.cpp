/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
	if (numerator == 0)
		return "0";
	if (denominator == 0)
		return "Illegal";

	string ret = "";

	if (numerator < 0 ^ denominator < 0) // If num < 0 and den < 0 - 1 ^ 1 which is 0. That is, don't set '-' sign. Only set sign if 1 of them is negative.
		ret += "-";

	long num = numerator < 0 ? (long)numerator * -1 : (long)numerator;
	long den = denominator < 0 ? (long)denominator * -1 : (long)denominator;
	long q, r;
	unordered_map<long, long> map;

	q = num / den;
	ret += to_string(q);
	if (num % den == 0)
		return ret;
	ret += ".";
	r = num % den;
	r *= 10;

	while (r) {
		q = r / den;
		if (map.find(r) != map.end()) {
			ret.insert(map[r], "(");
			ret += ")";
			break;
		}
		map[r] = ret.size();
		ret += to_string(q);
		r = (r % den) * 10;
	}

	return ret;
}

int main () {
	int i, num, den;

	cout << "\n Enter (num, den): ";
	cin >> num >> den;

	cout << "\n Decimal is: " << fractionToDecimal(num, den);

	cout << "\n\n";
	return 0;
}
