/*

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPowerOfThree(int n);

int main()
{
	int x;

	cout << "\n Enter number: ";
	cin >> x;

	if (isPowerOfThree(x))	
		cout << "\n The number is a power of three" << endl << endl;
	else
		cout << "\n The number is not a power of three" << endl << endl;

	return 0;
}

bool isPowerOfThree(int n)
{	
	long double x = log10(n) / log10(3);

	if (x != (int)x)
		return false;
	
	else
		return true;
}