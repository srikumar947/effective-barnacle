/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]


Buying the stock on ith day is considered as a transaction

opt[i][0] = Max value at ith day with 0 stock in hand (after all possible transactions)
opt[i][1] = Max value at ith day with 1 stock in hand (after all possible transactions)

*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() < 1)
        return 0;

	int i, flag = 0, **opt;
	opt = new int* [prices.size()];
	for (i = 0; i < prices.size(); i++)
		opt[i] = new int[2];

	opt[0][0] = 0;
	opt[0][1] = -prices[0];

	for (i = 1; i < prices.size(); i++) {
		opt[i][0] = max(opt[i - 1][0], opt[i - 1][1] + prices[i]);				// You can have 0 stock in the end if you rest from [i - 1][0] or sell from [i - 1][1]

		if (i != 1)																// because when i is 1, i -2 is -1 and opt[-1] doesn't exist.
			opt[i][1] = max(opt[i - 1][1], opt[i - 2][0] - prices[i]);			// You can have 1 stock in the end if you rest from [i - 1][1] or buy from [i - 2][0] due to cooldown period
		else
			opt[i][1] = max(opt[i - 1][1], -prices[i]);
	}

	return opt[prices.size() - 1][0];
}

int main() {
	vector<int> prices;
	int n, x;

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
/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]


Buying the stock on ith day is considered as a transaction

opt[i][0] = Max value at ith day with 0 stock in hand (after all possible transactions)
opt[i][1] = Max value at ith day with 1 stock in hand (after all possible transactions)

*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() < 1)
        return 0;

	int i, flag = 0, **opt;
	opt = new int* [prices.size()];
	for (i = 0; i < prices.size(); i++)
		opt[i] = new int[2];

	opt[0][0] = 0;
	opt[0][1] = -prices[0];

	for (i = 1; i < prices.size(); i++) {
		opt[i][0] = max(opt[i - 1][0], opt[i - 1][1] + prices[i]);				// You can have 0 stock in the end if you rest from [i - 1][0] or sell from [i - 1][1]

		if (i != 1)																// because when i is 1, i -2 is -1 and opt[-1] doesn't exist. opt[-1][0] = 0
			opt[i][1] = max(opt[i - 1][1], opt[i - 2][0] - prices[i]);			// You can have 1 stock in the end if you rest from [i - 1][1] or buy from [i - 2][0] due to cooldown period
		else
			opt[i][1] = max(opt[i - 1][1], -prices[i]);
	}

	return opt[prices.size() - 1][0];
}

int main() {
	vector<int> prices;
	int n, x;

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
