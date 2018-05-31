/*
n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

You can keep inputting the password, the password will automatically be matched against the last n digits entered.

For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

Example 1:
Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.
Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.
Note:
n will be in the range [1, 4].
k will be in the range [1, 10].
k^n will be at most 4096.

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

bool dfs(string previous, unordered_set<string>& visited, int& n, int& k, int& total, string& ret) {
    if (visited.size() == total)
        return true;
    string next;
    for (int i = 0; i < k; i++) {
        next = previous + to_string(i);
        if (visited.count(next) == 0) {
            visited.insert(next);
            ret += to_string(i);
            if (dfs(next.substr(1), visited, n, k, total, ret))
                return true;
            else {
                visited.erase(next);
                ret.erase(ret.size() - 1, 1);
            }
        }
    }
    return false;
}

string crackSafe(int n, int k) {
    int total = pow(k, n), i = 0;
    unordered_set<string> visited;
    string ret = "";

    for (i = 0; i < n; i++)
        ret += "0";

    visited.insert(ret);
    dfs(ret.substr(1), visited, n, k, total, ret);

    return ret;
}

int main() {
    int n, k;
    string s;

    cout << "\n Enter (n, k): ";
    cin >> n >> k;

    s = crackSafe(n, k);

    cout << "\n Minimum Length string: " << s;

    cout << "\n\n";
    return 0;
}
