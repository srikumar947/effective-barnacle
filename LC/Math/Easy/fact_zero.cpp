/*

Given a positive integer num, find number of trailing zeroes of its factorial.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int trailingZeros(int n);

int main()
{
	int x;

	cout << "\n Enter number: ";
	cin >> x;

	 cout << "\n Number of zeros: " << trailingZeros(x);

	cout << "\n\n";

	return 0;
}

int trailingZeros(int n) {
	if (n == 0)
	 	return 0;
	else
		return n / 5 + trailingZeros(n / 5);
}
