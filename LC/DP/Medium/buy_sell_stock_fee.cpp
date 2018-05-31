/*

You are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

opt[i][0] = Max value at ith day with 0 stock in hand (after all possible transactions)
opt[i][1] = Max value at ith day with 1 stock in hand (after all possible transactions)

Awesome explanation - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems
*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
	if (prices.size() < 1)
        return 0;
		
	int i, **opt;
	opt = new int* [prices.size()];
	for (i = 0; i < prices.size(); i++)
		opt[i] = new int[2];

	opt[0][0] = 0;
	opt[0][1] = -prices[0] - fee;

	for (i = 1; i < prices.size(); i++) {
		opt[i][0] = max(opt[i - 1][0], opt[i - 1][1] + prices[i]);				// You can have 0 stock in the end if you rest from [i - 1][0] or sell from [i - 1][1]
		opt[i][1] = max(opt[i - 1][1], opt[i - 1][0] - prices[i] - fee);		// You can have 1 stock in the end if you rest from [i - 1][1] or buy from [i - 1][0]
	}

	return opt[prices.size() - 1][0];
}

int main() {
	vector<int> prices;
	int n, fee, x;

	cout << "\n Enter number of days: ";
	cin >> n;

	cout << "\n Enter fee: ";
	cin >> fee;

	cout << "\n Enter stock values:  ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		prices.push_back(x);
	}

	cout << "\n Max Profit: " << maxProfit(prices, fee);

	cout << "\n\n";

	return 0;
}
