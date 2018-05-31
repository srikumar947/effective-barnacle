/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> Two_Sum (vector<int> numbers, int target)
{
	vector<int> ret;
    unordered_map <int, int> map;
    int x, diff, i;
    
    for(i = 0; i < numbers.size(); i++)
    {
        x = numbers.at(i);
        diff = target - x;
        if (map[diff])
        {
            ret.push_back(i);
        }
        map[x] = 1;
    }
    for(i = 0; i < numbers.size(); i++)
    {
        if ((numbers.at(i) +  numbers.at(ret.at(0)) == target) && (i != ret.at(0)))
        {
            ret.insert(ret.begin(), i);
            break;
        }
    }
    return ret;
}

int main()
{
	vector<int> numbers;
	vector<int> solution;
	int target, n, x;

	cout << "\n Enter the number of elemnets: ";
	cin >> n;
	
	cout << "\n Enter the array: ";
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		numbers.push_back(x);
	}

	cout << "\n Enter the target sum: ";
	cin >> target;

	solution = Two_Sum(numbers, target);

	cout << "\n The solution is: " << solution.at(0) << ", " << solution.at(1) << endl;

	return 0;
}