/*
Given two lists A and B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
Note:

A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
	vector<int> ret(A.size(), -1);
	unordered_map<int, int> map;
	for (int i = 0; i < B.size(); i++)
		map[B[i]] = i;
	for (int i = 0; i < A.size(); i++)
		ret[i] = map[A[i]];
	return ret;
}

int main () {
	vector<int> A, B;
	int i, x, n;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter List A: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		A.push_back(x);
	}

	cout << "\n Enter List B: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		B.push_back(x);
	}

	vector<int> ret = anagramMappings(A, B);
	cout << "\n Mapping: ";
	for (i = 0; i < n; i++)
		cout << ret[i] << " ";

	cout << "\n\n";
	return 0;
}
