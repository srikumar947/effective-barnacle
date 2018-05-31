/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    vector<int> temp;

    if (numRows < 1)
        return ret;

    temp.push_back(1);
    ret.push_back(temp);

    if (numRows == 1)
        return ret;

    temp.push_back(1);
    ret.push_back(temp);

    for (int i = 2; i < numRows; i++) {
        temp.clear();
        temp.push_back(1);
        for (int j = 0; j <= i - 2; j++)
            temp.push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
        temp.push_back(1);
        ret.push_back(temp);
    }
    return ret;
}

int main() {
    int n;
    vector<vector<int>> ret;

    cout << "\n Enter n: ";
    cin >> n;

    ret = generate(n);

    cout << "\n Pascal's Triangle - \n";
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";
    return 0;
}
