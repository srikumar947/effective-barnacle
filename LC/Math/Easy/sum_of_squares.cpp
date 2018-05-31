/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
*/

#include <iostream>
#include <cmath>

using namespace std;

bool judgeSquareSum(int c);

int main()
{
	int a;

	cout << "\n Enter number : ";
	cin >> a;

	cout << "\n Number is Sum of Squares: " << judgeSquareSum(a);

	cout << "\n\n";

	return 0;
}

bool judgeSquareSum(int c) {
    int b = 0, e = (int)sqrt(c);

    while (b <= e) {
        long sum = b * b + e * e;
        if (sum == c) {
            return true;
        }
		else if (sum >= c) {
            e--;
        }
		else {
            b++;
        }
    }
    return false;
}
