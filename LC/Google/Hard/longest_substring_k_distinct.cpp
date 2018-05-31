/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> map;
    int distinct = 0, ret = 0, i = 0, j = 0;

    for (i = 0; i < s.size(); i++) {
        distinct += (map[s[i]]++ == 0);                     // If the character isn't already present in map, then we increase distinct by 1.

        while (distinct > k)                                // While distinct is not equal to k, we keep deleting elements from start.
            distinct -= (--map[s[j++]] == 0);               // We reduce distinct by 1 only if reducing the count of a character goes to 0. Meaning, the character has been removed from the substring.

        ret = max(ret, i - j + 1);                          // Keep track of max length.
    }

    return ret;
}

int main() {
    int ret, k;
    string s;

    cout << "\n Enter (string, k): ";
    cin >> s >> k;

    ret = lengthOfLongestSubstringKDistinct(s, k);

    cout << "\n Length of longest substring with at most k distinct characters: " << ret;

    cout << "\n\n";
    return 0;
}
