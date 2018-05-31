/*
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.

Naive approach, O(nk) is TLE.
    Find max distance and place a station in between. Repeat until k is 0. Find max distance in resulting order.

Priority Queue, Heap O(k log(n)) is TLE.
    Similar to Naive approach but maintain max distance at the front of the queue or heap. This will reduce complexity to O(log(n)) instead of O(n) for every step (k steps).

Use trial and error method along with Binary search. O(n log(M)) where M = max distance initially / precision.
1. Find the maximum distance between any two adjacent stations in the list. This can be done in O(n).
2. Set left = 0, right to the max distance. We have been given an error range of 1e-6.
3. while left + precision < right
    i) Compute d as the mid of those two values.
    ii) Compute the number of stations you need to add between each pair of stations to achieve this value of d.
    iii) If the count is greater than k, then, we need to increase our value of d. Hence, move left to mid.
    iv) Else, if count is less than or equal to k, we can decrease d further. Move right to mid.
4. Return left after loop ends.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double minmaxGasDist(vector<int>& stations, int K) {
    int i = 0, n = stations.size(), count = 0;
    double max = stations[1] - stations[0];

    for (i = 2; i < n; i++)
        if (max < (stations[i] - stations[i - 1]))
            max = stations[i] - stations[i - 1];

    double left = 0, right = max, precision = 1e-6, d;

    while (left + precision <= right) {
        d = (left + right) / 2;
        count = 0;

        for (i = 1; i < n; i++)
            count += ceil((stations[i] - stations[i - 1]) / d) - 1;         // You can't have fraction of a station. Hence, ceil the number to get number of stations added.

        if (count <= K)
            right = d;
        else
            left = d;
    }

    return left;
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

    cout << "\n Enter K: ";
    cin >> k;

    cout << "\n Minimum distance to gas station: " << minmaxGasDist(nums, k);

    cout << "\n\n";
    return 0;
}
