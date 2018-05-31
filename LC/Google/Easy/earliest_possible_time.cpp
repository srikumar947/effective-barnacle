/*
Given a time represented in the format "HH:MM", form the earliest possible time by reusing the current digits. Each digit can be used only once.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Find the earliest possible time with the permutation of given time.

Example 1
Input  - 16:13
Output - 11:36

Example 2
Input  - 11:35
Output - 11:35

Example 3
Input  - 09:56
Output - 06:59

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

string earliestPossibleTime(string time) {
    vector<char> numbers;
    unordered_map<char, int> map;

    int i;

    for (i = 0; time[i]; i++) {
        if (time[i] != ':')
            numbers.push_back(time[i]);
    }

    sort(numbers.begin(), numbers.end());

    time[4] = numbers[3];

    for (i = 0; i < 3; i++)
        map[numbers[i]] = 1;

    for (i = 2; i >= 0; i--) {
        if (numbers[i] < '6') {
            time[3] = numbers[i];
            map[numbers[i]] = 0;
            break;
        }
    }

    for (i = 2; i >= 0; i--) {
        if (map[numbers[i]] != 0) {
            time[1] = numbers[i];
            map[numbers[i]] = 0;
            break;
        }
    }

    for (i = 2; i >= 0; i--) {
        if (map[numbers[i]] != 0) {
            time[0] = numbers[i];
            map[numbers[i]] = 0;
            break;
        }
    }

    return time;
}

int main () {
    string input;
    int K;

    cout << "\n Enter the Time in HH:MM - ";
    cin >> input;

    input = earliestPossibleTime(input);

    cout << "\n Earliest Possible Time is - " << input;

    cout << "\n\n";

    return 0;
}
