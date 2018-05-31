/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


opt[i][0] = Max profit on ith day after 1 transaction and 0 stock in hand (after all possible transactions are completed)
opt[i][1] = Max profit on ith day after 1 transaction and 1 stock in hand (after all possible transactions are completed)


*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Convoluted solution
int maxProfit2(vector<int>& prices) {
	// opt[i][0][0] = Max profit on ith day after 0 transactions and 0 stock in hand (after all possible transactions are completed)
	// opt[i][0][1] = Max profit on ith day after 0 transactions and 1 stock in hand (after all possible transactions are completed)
	// opt[i][1][0] = Max profit on ith day after 1 transaction and 0 stock in hand (after all possible transactions are completed)
	// opt[i][1][1] = Max profit on ith day after 1 transaction and 1 stock in hand (after all possible transactions are completed)

	if (prices.size() < 1)
        return 0;

	int i, j, ***opt;

	opt = new int** [prices.size()];
	for (i = 0; i < prices.size(); i++) {
		opt[i] = new int* [2];
		for (j = 0; j < 2; j++)
			opt[i][j] = new int[2];
	}

	opt[0][0][0] = 0;				// 0 transaction + 0 stock on 1st day means nothing is done
	opt[0][0][1] = INT_MIN;			// 0 transaction + 1 stock on 1st day is impossible
	opt[0][1][0] = INT_MIN;			// 1 transaction + 0 stock on 1st day is impossible
	opt[0][1][1] = -prices[0];		// 1 transaction + 1 stock on 1st day means stock was purchased

	for (i = 1; i < prices.size(); i++) {
		opt[i][0][0] = 0;															// 0 transaction + 0 stock means nothing is done
		opt[i][0][1] = INT_MIN;														// 0 transaction + 1 stock is impossible becuase buying a stock is marked as a transaction.
		opt[i][1][0] = max(opt[i - 1][1][0], opt[i - 1][1][1] + prices[i]);			// 1 transaction + 0 stock on day i means either rest from day [i-1][1][0] or sell from [i-1][1][1]
		opt[i][1][1] = max(opt[i - 1][1][1], opt[i - 1][0][0] - prices[i]);			// 1 transaction + 1 stock on day i means either rest from day [i-1][1][1] or buy from [i-1][0][0]
	}

	return max(opt[prices.size() - 1][1][0], 0);			// If stock values are in decreasing order, you've to return 0 instead of maximum negative profit.
	// return opt[last day][1][0] = max possible profit from given stock values. It can be negative - 7, 5, 3, 2. It'll return -1. Hence, return 0 if max profit is negative.

}

int maxProfit(vector<int>& prices) {
	if (prices.size() < 1)
        return 0;

	int i, **opt;

	opt = new int* [prices.size()];
	for (i = 0; i < prices.size(); i++)
		opt[i] = new int [2];

	opt[0][0] = 0;															// 0 stock on 1st day means nothing is done
	opt[0][1] = -prices[0];													// 1 stock on 1st day means stock was purchased

	for (i = 1; i < prices.size(); i++) {
		opt[i][0] = max(opt[i - 1][0], opt[i - 1][1] + prices[i]);			// 0 stock on day i means either rest from day [i-1][1][0] or sell from [i-1][1][1]
		opt[i][1] = max(opt[i - 1][1], - prices[i]);						// 1 stock on day i means either rest from day [i-1][1][1] or buy on day[i]
	}

	return opt[prices.size() - 1][0];										// If stock values are in decreasing order, you've to return 0 instead of maximum negative profit.
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
