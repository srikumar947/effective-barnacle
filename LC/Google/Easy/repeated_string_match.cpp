/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

For example, with A = "abcabcabcabc" and B = "abac".

Return -1.

Note:
The length of A and B will be between 1 and 10000.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
 
int repeatedStringMatch(string A, string B) {
    string copy = "";
    unordered_map<char, int> map;
    int i, counter = 0;

    for (i = 0; i < A.size(); i++)
        map[A[i]] = 1;

    for (i = 0; i < B.size(); i++)
        if (map[B[i]] != 1)
            return -1;

    while (B.length() >= copy.length()) {
        copy += A;
        counter += 1;

        if (copy.find(B) != string::npos)
            return counter;
    }

    copy += A;
    counter += 1;

    if (copy.find(B) != string::npos)
        return counter;

    return -1;
}

int main () {
    string A, B;

    cout << "\n Enter A: ";
    cin >> A;

    cout << "\n Enter B: ";
    cin >> B;

    cout << "\n Min number of repetitions: " << repeatedStringMatch(A, B);

    cout << "\n\n";

    return 0;
}
