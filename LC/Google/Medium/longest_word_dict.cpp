/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool checkString(string dict_word, string str) {
    int i = 0, j = 0;
    for (i = 0, j = 0; i < str.size() && j < dict_word.size(); i++)
        if (str[i] == dict_word[j])
            j += 1;
    return j == dict_word.size();
}

string findLongestWord(string s, vector<string>& d) {
    string ret = "", dict_word;
    int i, n = d.size();

    for (i = 0; i < n; i++) {
        dict_word = d[i];
        if (checkString(dict_word, s) && ((dict_word.size() > ret.size()) || ((dict_word.size() == ret.size()) && (dict_word < ret))))
            ret = dict_word;
    }

    return ret;
}

int main () {
    vector<string> d;
    string s, x;

    int i, n, t;

    cout << "\n Enter number of words: ";
    cin >> n;

    cout << "\n Enter words: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        d.push_back(x);
    }

    cout << "\n Enter the string to compare: ";
    cin >> s;

    s = findLongestWord(s, d);

    cout << "\n Longest Word: " << s;

    cout << "\n\n";
}
