/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	if (temperatures.size() < 1)
		return vector<int>(0);

	stack<int> st;
	vector<int> ret(temperatures.size(), 0);

	for (int i = temperatures.size() - 1; i >= 0; i--) {
		while (!st.empty() && temperatures[i] >= temperatures[st.top()])
			st.pop();
		ret[i] = st.empty() ? 0 : st.top() - i;
		st.push(i);
	}

	return ret;
}

int main () {
	vector<int> temp;
	int i, x, n;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter temperature values: ";
	for (i = 0; i < n; i++) {
		cin >> x;
		temp.push_back(x);
	}

	vector<int> ret = dailyTemperatures(temp);

	cout << "\n Wait Times: ";
	for (i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";

	cout << "\n\n";
	return 0;
}
