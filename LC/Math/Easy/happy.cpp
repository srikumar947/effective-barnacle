/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

*/

#include <iostream>
#include <unordered_map>

using namespace std;

bool isHappy(int n);

int square(int n);

int main()
{
	int x;

	cout << "\n Enter number: ";
	cin >> x;

	if (isHappy(x))	
		cout << "\n The number is happy" << endl << endl;
	else
		cout << "\n The number is not happy" << endl << endl;

	return 0;
}

int square(int n)
{
	int temp, sum = 0;

	while (n)
	{
		temp = n % 10;
		temp *= temp;
		sum += temp;
		n /= 10;
	}

	return sum;
}

bool isHappy(int n)
{	
	if (n == 0)
		return false;

	if (n == 1)
		return true;

	int slow = n, fast = n;
	fast = square (fast);

	while (slow != fast)
	{
		slow = square(slow);
		fast = square(fast);
		fast = square(fast);
	}

	if (slow == 1)
		return true;
	else
		return false;
}