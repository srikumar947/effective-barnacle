/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string nextClosestTime(string time) {
    vector<char> numbers;
    int i;

    for (i = 0; time[i]; i++) {
        if (time[i] != ':')
            numbers.push_back(time[i]);
    }

    sort(numbers.begin(), numbers.end());

    for (i = 0; i < 4; i++) {
        if (numbers[i] > time[4]) {
            time[4] = numbers[i];
            return time;
        }
    }

    time[4] = numbers[0];

    for (i = 0; i < 4; i++) {
        if (numbers[i] > time[3] && numbers[i] < '6') {
            time[3] = numbers[i];
            return time;
        }
    }

    time[3] = numbers[0];

    for (i = 0; i < 4; i++) {
        if (numbers[i] > time[1] && (numbers[i] < '4' || time[0] < '2')) {
            time[1] = numbers[i];
            return time;
        }
    }

    time[1] = numbers[0];

    for (i = 0; i < 4; i++) {
        if (numbers[i] > time[0] && numbers[i] <= '2') {
            time[0] = numbers[i];
            return time;
        }
    }

    time[0] = numbers[0];

    return time;
}

int main () {
    string input;
    int K;

    cout << "\n Enter the Time in HH:MM - ";
    cin >> input;

    input = nextClosestTime(input);

    cout << "\n Next Closest Time is - " << input;

    cout << "\n\n";

    return 0;
}
