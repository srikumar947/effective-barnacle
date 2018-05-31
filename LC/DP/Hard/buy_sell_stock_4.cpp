/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
	if ((prices.size() < 1) || (k < 1))
        return 0;

	/*
	Solution will not work for large values of k (greater than 1e+07). Not enough memory to allocate. Time Limit Exceeded.
	Hence, make an optimization based on k. There can't be more than n/2 transactions for any given input (each transaction involves buying on 1 day and selling on another day). If k > n/2, it is equivalent to infinite number of transactions.
	*/

	if (k > prices.size()/2) {
		int i, **opt;

		opt = new int*[prices.size()];
	    for (i = 0; i < prices.size(); i++)
			opt[i] = new int[2];

		opt[0][0] = 0;
		opt[0][1] = -prices[0];

		for (i = 1; i < prices.size(); i++) {
			opt[i][0] = max(opt[i - 1][0], opt[i - 1][1] + prices[i]);
			opt[i][1] = max(opt[i - 1][1], opt[i - 1][0] - prices[i]);
		}

		return opt[prices.size() - 1][0];
	}

	else {
		int i, j, ***opt;

		opt = new int**[prices.size()];
	    for (i = 0; i < prices.size(); i++) {
	        opt[i] = new int*[k];
	        for (j = 0; j < k; j++) {
	            opt[i][j] = new int[2];
	        }
	    }


		for (j = 0; j < k ; j++) {
			opt[0][j][0] = 0;
			opt[0][j][1] = -prices[0];
		}

		for (i = 1; i < prices.size(); i++) {
			for (j = 0; j < k; j++) {
				opt[i][j][0] = max(opt[i - 1][j][0], opt[i - 1][j][1] + prices[i]);
				if (j == 0)
					opt[i][j][1] = max(opt[i - 1][j][1], -prices[i]);
				else
					opt[i][j][1] = max(opt[i - 1][j][1], opt[i - 1][j - 1][0] - prices[i]);
			}
		}

		int max = opt[prices.size() - 1][0][0];
		for (j = 1; j < k; j++) {
			if (max < opt[prices.size() - 1][j][0])
				max = opt[prices.size() - 1][j][0];
		}
		return max;
	}
}

int main() {
	vector<int> prices;
	int n, k, x;

	cout << "\n Enter number of days: ";
	cin >> n;

	cout << "\n Enter k: ";
	cin >> k;

	cout << "\n Enter stock values:  ";
	for (int i = 0; i < n; i++) {
		cin >> x;
		prices.push_back(x);
	}

	cout << "\n Max Profit: " << maxProfit(k, prices);

	cout << "\n\n";

	return 0;
}
