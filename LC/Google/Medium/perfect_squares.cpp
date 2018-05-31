/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

#include <iostream>
#include <climits>

using namespace std;

int numSquares(int n) {
    int ret[n + 1];
    for (int i = 1; i < n + 1; i++)
        ret[i] = INT_MAX;
    ret[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j*j <= i; j++)
            ret[i] = min(ret[i], ret[i - j*j] + 1);

    return ret[n];
}

int main () {
    int n;
    cout << "\n Enter n: ";
    cin >> n;

    n = numSquares(n);

    cout << "\n Least number of squares: " << n;

    cout << "\n\n";
}
