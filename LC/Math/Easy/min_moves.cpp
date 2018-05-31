/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

This is equivalent to subtracting 1 element by 1 in each move. Hence, all you need to know is the difference between every element and the minimum element. The sum of all the differences will give the number of moves.

Another way of solving it is to think of it as follows -

n = number of elements
sum = initial sum of all numbers
m = moves
x = final value of all numbers

sum + m * (n - 1) = x * n
x = minNum + m
Thus,
m = sum - minNum * n

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int min(vector<int>& nums)
{
	int temp = nums[0], pos = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] < temp)
		{
			temp = nums[i];
			pos = i;
		}
	}
	return pos;
}

int minMoves(vector<int>& nums)
{
	if (nums.size() == 1)
		return 0;

	int n = nums.size(), moves = 0, pos = min(nums), i = 0;

	while (i < n)
	{
		if (pos != i)
			moves += nums[i] - nums[pos];
		i += 1;
	}

	return moves;
}

int minMoves2(vector<int>& nums) {
	int sum, min, moves;

	min = nums[0];
	sum = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		sum += nums[i];
		if (min > nums[i])
			min = nums[i];
	}

	moves = sum - (min * nums.size());

	return moves;
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

	cout << "\n The minimum number of moves is: " << minMoves2(x) << endl;

	return 0;
}
