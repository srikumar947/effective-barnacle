/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> countBits(int num) {
	vector<int> ret(num+1, 0);
    for (int i = 1; i <= num; ++i)
        ret[i] = ret[i&(i-1)] + 1;
    return ret;
}

int main() {
	int n, x;
	vector<int> nums;

	cout << "\n Enter n: ";
	cin >> n;

	nums = countBits(n);

	cout << "\n Return vector - \n";

	for (int i = 0; i <= n; i++) {
		cout << " " << nums[i];
	}

	cout << "\n\n";

	return 0;
}
