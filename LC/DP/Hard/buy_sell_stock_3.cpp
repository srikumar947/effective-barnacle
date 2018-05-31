/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

opt[i][0][0] = Max profit on ith day after 1 transaction and 0 stock in hand (after all possible transactions are completed)
opt[i][0][1] = Max profit on ith day after 1 transaction and 1 stock in hand (after all possible transactions are completed)
opt[i][1][0] = Max profit on ith day after 2 transactions and 0 stock in hand (after all possible transactions are completed)
opt[i][1][1] = Max profit on ith day after 2 transactions and 1 stock in hand (after all possible transactions are completed)

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() < 1)
        return 0;

	int i, j, ***opt;

	opt = new int** [prices.size()];
	for (i = 0; i < prices.size(); i++) {
		opt[i] = new int* [2];
		for (j = 0; j < 2; j++)
			opt[i][j] = new int[2];
	}

	opt[0][0][0] = 0;
	opt[0][0][1] = -prices[0];
	opt[0][1][0] = INT_MIN;
	opt[0][1][1] = INT_MIN;

	for (i = 1; i < prices.size(); i++) {
		opt[i][0][0] = max(opt[i - 1][0][0], opt[i - 1][0][1] + prices[i]);			// 1 transaction + 0 stock on day i means either rest from day [i-1][0][0] or sell from [i-1][0][1]
		opt[i][0][1] = max(opt[i - 1][0][1], -prices[i]);							// 1 transaction + 1 stock on day i means either rest from day [i-1][0][1] or buy on day i
		opt[i][1][0] = max(opt[i - 1][1][0], opt[i - 1][1][1] + prices[i]);			// 2 transactions + 0 stock on day i means either rest from day [i-1][1][0] or sell from [i-1][1][1]
		opt[i][1][1] = max(opt[i - 1][1][1], opt[i - 1][0][0] - prices[i]);			// 2 transactions + 1 stock on day i means either rest from day [i-1][1][1] or buy from [i-1][0][0]
	}

	return max(opt[prices.size() - 1][1][0], opt[prices.size() - 1][0][0]);			// If stock values are in decreasing order, you've to return 0 instead of maximum negative profit.
}

int main() {
	vector<int> prices;
	int n, fee, x;

	cout << "\n Enter number of days: ";
	cin >> n;

	cout << "\n Enter stock values:  ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		prices.push_back(x);
	}

	cout << "\n Max Profit: " << maxProfit(prices);

	cout << "\n\n";

	return 0;
}
