/*
Given an input string, reverse the string word by word.

Example:

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reversePart(string &s, int start, int end) {
    while (start < end) {
        char t = s[end];
        s[end--] = s[start];
        s[start++] = t;
    }
}

void reverseWords(string &s) {
    int i = 0, j = 0;

    while (s[0] == ' ')
        s.erase(s.begin());

    while (i < s.size()) {
        while (i < s.size() - 1 && s[i] == ' ' && s[i + 1] == ' ')
            s.erase(s.begin() + i);

        if (s[i] == ' ')
            i += 1;

        j = i;

        while (i < s.size() && s[i] != ' ')
            i += 1;

        reversePart(s, j, i - 1);
    }

    reverse(s.begin(), s.end());

    while (s[0] == ' ')
        s.erase(s.begin());
}

int main() {
    string s = "1 ";

    reverseWords(s);

    cout << "\n Reversed string: " << s;

    cout << "\n\n";
    return 0;
}
