/*
Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]

If a < 0, we get a downward parabola. That is, in the array, the centre element will have the max value and will start dropping to either side of it till the ends.
If a > 0, we get an upward parabola. That is, in the array, the centre element will have the min value and will start increasing to either side of it till the ends.
We will use two pointers, one starts from 0 and the other from the end. We compare the values of these two and store the result accordingly (merge sort's merge procedure).
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int transform(int value, int a, int b, int c) {
    return ((value * value * a) + (value * b) + c);
}

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    if (nums.size() < 1)
        return vector<int>();

    vector<int> ret(nums.size());
    int i = 0, j = nums.size() - 1, k, n = nums.size(), x, y;

    if (a > 0) {
        k = n - 1;
        while (i <= j) {
            x = transform(nums[i], a, b, c);
            y = transform(nums[j], a, b, c);
            if (x > y) {
                ret[k--] = x;
                i += 1;
            }
            else {
                ret[k--] = y;
                j -= 1;
            }
        }
    }
    else {
        k = 0;
        while (i <= j) {
            x = transform(nums[i], a, b, c);
            y = transform(nums[j], a, b, c);
            if (x < y) {
                ret[k++] = x;
                i += 1;
            }
            else {
                ret[k++] = y;
                j -= 1;
            }
        }
    }
    return ret;
}

int main() {
    vector<int> nums;
    int i, n, x, a, b, c;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter the values: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    cout << "\n Enter (a, b, c): ";
    cin >> a >> b >> c;

    vector<int> ret = sortTransformedArray(nums, a, b, c);

    cout << "\n Transformed Array: ";
    for (i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";

    cout << "\n\n";
    return 0;
}
