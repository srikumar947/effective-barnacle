/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
    
    int n = nums.size();
    
    int max1 = nums[n-1]*nums[n-2]*nums[n-3];
    
    int max2 = nums[0]*nums[1]*nums[n-1];
    
    if (max1 > max2)
    	return max1;

    return max2;
}

int main()
{
	vector <int> x;
	int i, n, y;

	cout << "\n Enter the number of elements: ";
	cin >> n;

	cout <<"\n Enter the elements: ";

	for (i = 0; i < n; i++)
	{
		cin >> y;
		x.push_back(y);
	}

	cout << "\n The Maximum product is: " << maximumProduct(x) << endl;

	return 0;
}