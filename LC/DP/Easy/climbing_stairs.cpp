/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

If n is less than 1 - it means there are no steps. Hence return 0;
If n is equal to 1 - it means that there is 1 step and we have only 1 way to reach to the top.
If n is equal to 2 - it means that there are 2 steps and we have 2 ways to reach to the top. 1. step 1 + step 2 or 2. Directly step 2
For all other n values -
You start at step number 3.
Number of ways to reach step number 2 is 2. (n_1_step)
Number of ways to reach step number 1 is 1. (n_2_step)
To find number of ways to reach step number 3, we just need to add the number of ways to reach step number 2 and the number of ways to reach step number 1.
Continue this till you reach nth step.
*/

#include <iostream>

using namespace std;

int climbStairs(int n) {
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	int ret = 0, n_1_step = 2, n_2_step = 1;
	for (int i = 2; i < n; i++) {
		ret = n_1_step + n_2_step;
		n_2_step = n_1_step;
		n_1_step = ret;
	}

	return ret;
}

int main() {
	int n;

	cout << "\n Enter number of stairs: ";
	cin >> n;

	cout << "\n Number of distinct ways: " << climbStairs(n);

	cout << "\n\n";

	return 0;
}
