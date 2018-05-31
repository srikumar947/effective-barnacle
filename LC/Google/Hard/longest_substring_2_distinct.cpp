/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> map;
    int i = 0, j = 0, ret = 0, distinct = 0;
    for (i = 0; i < s.size(); i++) {
        distinct += (map[s[i]]++ == 0);
        while (distinct > 2)
            distinct -= (--map[s[j++]] == 0);
        ret = max(ret, i - j + 1);
    }
    return ret;
}

int main() {
    string s;

    cout << "\n Enter string: ";
    cin >> s;

    cout << "\n Longest substring with at most 2 distinct characters: " << lengthOfLongestSubstringTwoDistinct(s);

    cout << "\n\n";
    return 0;
}
