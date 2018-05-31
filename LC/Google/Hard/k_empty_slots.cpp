/*
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input:
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input:
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].

Use a sliding window. Get a days array that would state the day in which the flower at that position will bloom. If a flower blooms before our left and right, then this window is invalid.

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kEmptySlots(vector<int>& flowers, int k) {
    vector<int> days(flowers.size());
    int i = 0, n = flowers.size(), ret = INT_MAX, left = 0, right = k + 1;

    if (n < 1)
        return -1;

    for (i = 0; i < n; i++)
        days[flowers[i] - 1] = i + 1;

    for (i = 0; right < n; i++) {
        if (days[i] < days[left] || days[i] <= days[right]) {
            if (i == right)
                ret = min(ret, max(days[left], days[right]));

            left = i;
            right = i + k + 1;
        }
    }

    return ret == INT_MAX ? -1 : ret;
}

int main() {
    vector<int> nums;
    int i, n, x, k;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter the values: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    cout << "\n Enter k: ";
    cin >> k;

    int ret = kEmptySlots(nums, k);

    cout << "\n Day: " << ret;

    cout << "\n\n";
    return 0;
}
