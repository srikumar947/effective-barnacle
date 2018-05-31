/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int reverse(int x) {
    long long ret = 0;

    while (x) {
        ret = (ret * 10) + (x % 10);
        x /= 10;
    }

    return (ret < INT_MIN || ret > INT_MAX) ? 0 : ret;
}

int main() {
    int n;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Reversed integer: " << reverse(n);

    cout << "\n\n";
    return 0;
}
