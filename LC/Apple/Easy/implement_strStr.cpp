/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

#include <iostream>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {
    if (needle.size() < 1)
        return 0;

    int i = 0, j = 0, k, n = haystack.size(), m = needle.size(), pos;

    for (i = 0; i < n; i++) {
        if (haystack[i] == needle[0]) {
            pos = i;
            j = 1;
            k = i + 1;
            while (j < m && k < n) {
                if (haystack[k++] != needle[j++]) {
                    j = 0;
                    break;
                }
            }
            if (j == m)
                break;
        }
    }
    if (j == m)
        return pos;
    return -1;
}

int main() {
    string haystack, needle;

    cout << "\n Enter two strings: ";
    cin >> haystack >> needle;

    int ret = strStr(haystack, needle);
    cout << "\n First occurrence of " << needle << " in " << haystack << " is at " << ret;

    cout << "\n\n";
    return 0;
}
