/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
int start;
int end;
Interval() : start(0), end(0) {}
Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() < 1)
        return vector<Interval>{};

    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
    vector<Interval> ret;

    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start <= ret.back().end)
            ret.back().end = max(ret.back().end, intervals[i].end);
        else
            ret.push_back(intervals[i]);
    }

    return ret;
}

int main () {
    vector<Interval> intervals, ret;

    int i, x, y, n;

    cout << "\n Enter number of intervals: ";
    cin >> n;

    cout << "\n Enter the Intervals: ";
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        Interval in(x, y);
        intervals.push_back(in);
    }

    ret = merge(intervals);

    cout << "\n Merged: ";
    for (i = 0; i < ret.size(); i++)
        cout << "\n " << ret[i].start << " " << ret[i].end;

    cout << "\n\n";
}
