/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
*/

#include <iostream>
#include <cmath>

using namespace std;

bool checkPerfectNumber(int num);

int main()
{
	int a;

	cout << "\n Enter number : ";
	cin >> a;

	cout << "\n Number is Perfect: " << checkPerfectNumber(a);

	cout << "\n\n";

	return 0;
}

bool checkPerfectNumber(int num) {

	if (num <= 1)
		return false;

	int i = 1, sum = 0;
	while (i * i <= num) {
		if (num % i == 0) {
			sum += i + num/i;
		}
		i += 1;
	}
	if (sum != 2*num)
		return false;
	return true;
}
