/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums);

int main()
{
	int i, n, x;
	vector <int> nums;
	
	cout << "\n Enter n: ";
	cin >> n;
	
	cout << "\n Enter the numbers: ";
	
	for (i = 0; i < n; i++)
	{
		cin >> x;
		nums.push_back(x);
	}

	x = missingNumber(nums);
	
	cout << "\n The missing number is: " << x << endl << endl;

	return 0;
}

// Using sum - n*(n+1)/2
int missingNumber(vector<int>& nums)
{
	int sum, i = 0, n = nums.size();

	sum = n * (n + 1);
	sum /= 2;

	for (i = 0; i < nums.size(); i++)
	{
		sum -= nums[i];
	}

	return sum;
}

// Using XOR - num ^ num = 0 and num ^ 0 = num
int missingNumber2(vector<int>& nums)
{
	int res = nums.size(), i = 0;

	for (i = 0; i < nums.size(); i++)
	{
		res = res ^ nums[i];
		res = res ^ i;
	}

	return res;
}