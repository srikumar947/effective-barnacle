/*

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isUgly(int num);
vector<int> findPrime(int num);

int main()
{
	int x;

	cout << "\n Enter number: ";
	cin >> x;

	 cout << "\n Number is ugly: " << isUgly(x);

	cout << "\n\n";

	return 0;
}

/*

// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        printf ("%d ", n);
}

// 15 ms
bool isUgly(int num) {
	if (num < 1)
        return false;

	while(num % 2 == 0)
		num /= 2;

	for (int i = 3; i <= sqrt(num); i += 2) {

		while (num % i == 0) {
			if (i > 5)
				return false;
			num /= i;
		}
	}

	if (num > 5)
		return false;

	return true;
}
*/

bool isUgly(int num) {
	if (num < 1)
        return false;

	while(num % 2 == 0)
        num /= 2;

    while(num % 3 == 0)
        num /= 3;

    while(num % 5 == 0)
        num /= 5;

    if (num != 1)
        return false;
    else
        return true;
}
