/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx                                                   Case 1
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx                                          Case 2
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx                                 Case 3
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx                        Case 4
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.

A = 0011 0000
1)
A << 2
A = 1100 0000

2)
A >> 2
A = 0000 1100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

bool validUtf8(vector<int>& data) {
    int count = 0;
    for (auto x : data) {
        if (count == 0) {
            if (x >> 3 == 0b11110)                 // Shift to the right by 3 bits and check for case 4
                count = 3;
            else if (x >> 4 == 0b1110)             // Shift to the right by 4 bits and check for case 3
                count = 2;
            else if (x >> 5 == 0b110)              // Shift to the right by 5 bits and check for case 2
                count = 1;
            else if (x >> 7 == 0b1)                // Shift to the right by 7 bits and check for case 1. If the first octet starts with 1 when count is 0, then the data is invalid.
                return false;
        }
        else {
            if (x >> 6 != 0b10)                    // Shift to the right by 6 bits and check if the leading two bits are 10. If not, data is invalid.
                return false;
            count -= 1;                            // This has to be done till count is 0.
        }
    }
    return count == 0;                             // Only if count is 0 (all data values processed plus everything valid). e.g. 1110xxxx is invalid. If we don't check for count == 0, true will be returned.
}

int main () {
    int m,i, x;

    cout << "\n Enter m: ";
    cin >> m;

    vector<int> data(m);

    cout << "\n Enter data: ";

    for(i = 0; i < m; i++){
        cin >> x;
        data[i] = x;
    }

    cout << "\n Valid UTF-8: " << validUtf8(data);

    cout << "\n\n";
}
