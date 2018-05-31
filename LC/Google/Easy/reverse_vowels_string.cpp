/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char ch) {
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}


string reverseVowels(string s) {
    string vowels = "";

    for (auto c:s) {
        if (isVowel(c))
            vowels += c;
    }

    reverse(vowels.begin(), vowels.end());

    for (int i = 0, k = 0; i < s.size(); i++) {
        if (isVowel(s[i]))
            s[i] = vowels[k++];
    }

    return s;
}

int main () {
    string s;

    cout << "\n Enter string: ";
    cin >> s;

    cout << "\n Reversed: " << reverseVowels(s);

    cout << "\n\n";
}
