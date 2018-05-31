/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

Base Case -
If you're in the last step, you've to pay that step's cost.
If you're in the second last step, optimal would be to pay for that step and jump 2 to complete instead of jumping 1 and paying last step as well.

Compute opt for all steps and return min of either first step or second step.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	if (cost.size() < 1)
		return 0;

	int *opt = new int[cost.size()];
	int last = cost.size() - 1;

	opt[last] = cost[last];
	opt[last - 1] = cost[last - 1];

	for (int i = last - 2; i >= 0; i--) {
		opt[i] = cost[i] + min(opt[i + 1], opt[i + 2]);
	}

	return min(opt[0], opt[1]);
}

int main() {
	vector<int> cost;
	int n, x;

	cout << "\n Enter number of stairs: ";
	cin >> n;

	cout << "\n Enter stair cost values: ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		cost.push_back(x);
	}

	cout << "\n Min Cost: " << minCostClimbingStairs(cost);

	cout << "\n\n";

	return 0;
}
