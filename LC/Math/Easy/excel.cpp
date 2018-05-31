/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unsigned long titleToNumber(string s)
{
	unsigned long ret = 0;

	for (int i = 0; i < s.size(); i++)
	{
		ret = (ret * 26) + ((toupper(s[i])) - 'A' + 1);
	}

	return ret;
}

int main()
{
	string s;

	cout << "\n Enter the string: ";
	cin >> s;

	cout << "\n The column number is: " << titleToNumber(s) << endl;

	return 0;
}
