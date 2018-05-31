/*
Given two 1d vectors, implement an iterator to return their elements alternately.

Example:

Input:
v1 = [1,2]
v2 = [3,4,5,6]

Output: [1,3,2,4,5,6]

Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,3,2,4,5,6].
Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question:
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

Input:
[1,2,3]
[4,5,6,7]
[8,9]

Output: [1,4,8,2,5,9,3,6,7].

Your ZigzagIterator object will be instantiated and called as such:
ZigzagIterator i(v1, v2);
while (i.hasNext())
    cout << i.next();

*/

#include <iostream>
#include <vector>

using namespace std;

class ZigzagIterator {
public:
    int max, iterator;
    vector<int> v;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iterator = 0;

        max = v1.size();
        if (v2.size() > max)
            max = v2.size();

        for (int i = 0; i < max; i++) {
            if (i < v1.size())
                v.push_back(v1[i]);
            if (i < v2.size())
                v.push_back(v2[i]);
        }

        max = v.size();
    }

    int next() {
        return v[iterator++];
    }

    bool hasNext() {
        if (iterator < max)
            return true;
        else
            return false;
    }
};

int main () {
    vector<int> v1, v2;
    int n, i, x;

    cout << "\n Enter number of elements: ";
    cin >> n;

    cout << "\n Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        v1.push_back(x);
    }

    cout << "\n Enter number of elements: ";
    cin >> n;

    cout << "\n Enter elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        v2.push_back(x);
    }

    ZigzagIterator it(v1, v2);

    while (it.hasNext())
        cout << it.next() << " ";

    cout << "\n\n";
}
