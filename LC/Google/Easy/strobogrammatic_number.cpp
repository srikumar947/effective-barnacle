/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isStrobogrammatic(string num) {
    unordered_map <char, char> map {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
        if (map.find(num[i]) == map.end() || num[i] != map[num[j]])
            return false;
    }
    return true;
}

int main () {
    string s;

    cout << "\n Enter number: ";
    cin >> s;

    cout << "\n Strobogrammatic: " << isStrobogrammatic(s);

    cout << "\n\n";
}
