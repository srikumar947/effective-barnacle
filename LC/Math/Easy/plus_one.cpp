/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits);

int main()
{
	int n, x;
	vector<int> digits, ret;

	cout << "\n Enter number of digits: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\n Enter Digit " << i + 1 << " : ";
		cin >> x;
		digits.push_back(x);
	}

	ret = plusOne(digits);

	cout << "\n New vector is \n";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}

	cout << "\n\n";
	return 0;
}

vector<int> plusOne(vector<int>& digits) {
	vector<int> ret;
	int temp, carry = 0;

	for (int i = digits.size() - 1; i >= 0; i--) {

		if(i == digits.size() - 1)
			temp = digits[i] + carry + 1;
		else
			temp = digits[i] + carry;

		carry = 0;

		if (temp > 9) {
			carry = temp / 10;
			temp %= 10;
		}

		ret.push_back(temp);
	}

	if (carry)
		ret.push_back(carry);

	reverse(ret.begin(), ret.end());

	return ret;
}
