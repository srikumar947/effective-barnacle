/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPerfectSquare(int num);

int main()
{
	int x;

	cout << "\n Enter number: ";
	cin >> x;

	 cout << "\n Number is perfect: " << isPerfectSquare(x);

	cout << "\n\n";

	return 0;
}

bool isPerfectSquare(int num) {
	if (num < 1)
		return false;
	if (num == 1)
		return true;

	for (int i = 2; i <= num/2; i++) {
		if (i*i == num)
			return true;
		if (i*i > num)
			return false;
	}

	return false;
}
