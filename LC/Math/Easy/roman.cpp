/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
	int i = 0, num = 0, n = s.size();
	string x = "";
	unordered_map <string, int> map;

	map["I"] = 1;
	map["IV"] = 4;
	map["V"] = 5;
	map["IX"] = 9;
	map["X"] = 10;
	map["XL"] = 40;
	map["L"] = 50;
	map["XC"] = 90;
	map["C"] = 100;
	map["CD"] = 400;
	map["D"] = 500;
	map["CM"] = 900;
	map["M"] = 1000;
	
	while (i < n - 1)
	{
		x = x + s[i] + s[i + 1];
		
		if(map[x])
		{
			num += map[x];
			i += 2;
		}

		else
		{
			x = s[i];
			num += map[x];
			i += 1;
		}

		x = "";
	}

	if (i == n - 1)
	{
		x = s[i];
		num += map[x];
	}

	return num;
}

int main()
{
	string s;

	cout << "\n Enter the roman number: ";
	cin >> s;

	cout << "\n The number is: " << romanToInt(s) << endl;

	return 0;
}