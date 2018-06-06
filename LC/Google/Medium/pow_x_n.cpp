/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
*/

#include <iostream>

using namespace std;

/*
16 = 4^2 = 2^4 = 2^2 * 2^2
That's why we get the result for n/2.
If n was even, we just return the square of our result, else, we check n's sign and return num * num^(n/2) or (1/num) * num^(n/2)
*/
double myPow(double x, int n) {
	if (n == 0)
		return 1;

	double temp = myPow(x, n/2);

	if (n % 2)
		return n < 0 ? (1 / x) * temp * temp : x * temp * temp;

	return temp * temp;
}

int main () {
	int i, n;
	double x;

	cout << "\n Enter (x, n): ";
	cin >> x >> n;

	cout << "\n x^n = " << myPow(x, n);

	cout << "\n\n";
	return 0;
}
