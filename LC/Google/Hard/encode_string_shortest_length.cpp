/*
Given a non-empty string, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

Note:
k will be a positive integer and encoded string will not be empty or have extra space.
You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.
Example 1:

Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
Example 2:

Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
Example 3:

Input: "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
Example 4:

Input: "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
Example 5:

Input: "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int repetitions(string& t, string& s) {
    int i = 0, ret = 0;
    while (i < s.size()) {
        if (s.substr(i, t.size()) != t)
            break;
        ret += 1;
        i += t.size();
    }
    return ret;
}

string dfs(string s, unordered_map<string, string>& map) {
    if (s.size() < 5)
        return s;

    if (map.find(s) != map.end())
        return map[s];

    string ret = s;

    for (int i = 0; i < s.size(); i++) {
        string t = s.substr(0, i + 1);
        int count = repetitions(t, s);
        string check;
        for (int k = 1; k <= count; k++) {
            if (k == 1)
                check = t + dfs(s.substr(i + 1), map);
            else
                check = to_string(k) + "[" + dfs(t, map) + "]" + dfs(s.substr(k * t.size()), map);
            ret = check.size() < ret.size() ? check : ret;
        }
    }

    map[s] = ret;
    return ret;
}

string encode(string s) {
    unordered_map<string, string> map;
    return dfs(s, map);
}

int main() {
    string s;

    cout << "\n Enter string: ";
    cin >> s;

    cout << "\n Encoded: " << encode(s);

    cout << "\n\n";
    return 0;
}
