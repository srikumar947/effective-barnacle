/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string convertToTitle(int n)
{
	if (n == 0)
		return "";
	else
		return convertToTitle((n-1)/26) + (char)(((n - 1) % 26) + 'A');
}

int main()
{
	int x;

	cout << "\n Enter the integer: ";
	cin >> x;

	cout << "\n The column is: " << convertToTitle(x) << endl;

	return 0;
}
