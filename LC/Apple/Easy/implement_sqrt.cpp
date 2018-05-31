/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

Newton's integer square root method
*/

#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int x) {
    long long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
}

int main() {
    int n;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Square root: " << mySqrt(n);

    cout << "\n\n";
    return 0;
}
