/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
    int pos = 0, i = 0, j = 0, n = version1.size(), m = version2.size(), num1 = 0, num2 = 0;
    string temp;
    while (i < n || j < m) {
        if (i < n) {
            pos = version1.find('.', i);
            if (pos == -1)
                pos = n;
            temp = version1.substr(i, pos - i);
            num1 = stoi(temp);
            i = pos + 1;
        }

        if (j < m) {
            pos = version2.find('.', j);
            if (pos == -1)
                pos = m;
            temp = version2.substr(j, pos - j);
            num2 = stoi(temp);
            j = pos + 1;
        }

        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;

        num1 = 0;
        num2 = 0;
    }
    return 0;
}

int main() {
    string a, b;

    cout << "\n Enter versions: ";
    cin >> a >> b;

    cout << "\n Comparison (a, b): " << compareVersion(a, b);

    cout << "\n\n";
    return 0;
}
