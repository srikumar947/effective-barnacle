/*
Given an integer, return its cubic root.
Input 8
Output 2.00000

*/

#include <iostream>

using namespace std;

double difference(double a, double b) {
    if (a * a * a < b)
        return b - (a * a * a);
    return (a * a * a) - b;
}

double cubicRoot(double n) {
    double start = 0, end = n, mid, precision = 0.00001, check;

    while (true) {
        mid = (start + end) / 2;
        check = difference(mid, n);

        if (check <= precision)
            return mid;

        else if ((mid * mid * mid) > n)
            end = mid;

        else
            start = mid;
    }
}

int main() {
    double n;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Cube Root of " << n << " is " << cubicRoot(n);

    cout << "\n\n";
    return 0;
}
