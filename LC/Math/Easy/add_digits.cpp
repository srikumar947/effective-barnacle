/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime? = Use digital root properties.

*/

#include <iostream>

using namespace std;

/*
int addDigits(int num)	// 6ms
{
	if ((num / 10) == 0)
		return num;

	int sum = 0;

	while (num)
	{
		sum += num %10;
		num /= 10;
	}

	sum = addDigits(sum);

	return sum;
}
*/

int addDigits(int num) // 3 ms
{
	return (num-1)%9+1;
}


int main()
{
	int number;

	cout << "\n Enter the number: ";
	cin >> number;

	number = addDigits(number);

	cout << "\n The sum is: " << number << endl;

	return 0;
}
