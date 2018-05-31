/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Can you solve it without converting the integer to a string?
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPalindrome(int x);

int main()
{
	int x;

	cout << "\n Enter number: ";
	cin >> x;

	 cout << "\n Number is Palindrome: " << isPalindrome(x);

	cout << "\n\n";

	return 0;
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;

	if (x / 10 == 0)
		return true;

	long tmp = x;
    long reverse = 0;

    while (tmp)
    {
        reverse = reverse * 10 + (tmp % 10);
        tmp /= 10;
    }
    return reverse == x;
}

/*
// 288 ms
bool isPalindrome(int x) {

	if (x < 0)
		return false;

	if (x / 10 == 0)
		return true;

	int temp = 0, copy = x, n = 0;
	while (copy) {
		n += 1;
		copy /= 10;
	}

	int i = pow(10, n-1);
	copy = x;

	while (copy) {
		temp += ((copy % 10) * i);
		copy /= 10;
		i /= 10;
	}

	if (temp == x)
		return true;
	else
		return false;
}
*/
