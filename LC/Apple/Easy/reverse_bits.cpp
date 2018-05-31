/*
Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?

Basically, iterate over each bit in n and get the least significant 1 using (n & 1). Add this to ret (using OR |). Shift n by 1 to right and ret by 1 to left.
*/

#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++, n >>= 1) {
        ret <<= 1;
        ret = ret | (n & 1);
    }
    return ret;
}

int main() {
    uint32_t n;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Reversed integer: " << reverseBits(n);

    cout << "\n\n";
    return 0;
}
