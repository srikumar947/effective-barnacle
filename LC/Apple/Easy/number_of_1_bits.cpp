/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011
Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000


We check each of the 32 bits of the number. If the bit is 1, we add one to the count.

We can check the ith bit of a number using a bit mask. We start with a mask mask = 1, because the binary representation of 1 is,

0000 0000 0000 0000 0000 0000 0000 0001

A logical AND between any number and the mask 1 gives us the least significant bit of this number. To check the next bit, we shift the mask to the left by one.

0000 0000 0000 0000 0000 0000 0000 0010

Basically, we check if the AND resulted in a number that is not 0. If that's the case, then we have a 1 bit at that position.

*/

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0, mask = 1;

    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0)
            count += 1;
        mask <<= 1;
    }

    return count;
}

int main() {
    uint32_t n;
    cout << "\n Enter the integer: ";
    cin >> n;

    cout << "\n Number of 1s: " << hammingWeight(n);

    cout << "\n\n";
    return 0;
}
