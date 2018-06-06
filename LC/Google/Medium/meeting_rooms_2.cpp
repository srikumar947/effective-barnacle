/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

Input: [[1,5],[5,9]]
Output: 1
That is, if a meeting ends on i, another meeting can begin at i.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(vector<Interval>& intervals) {
	vector<pair<int, int>> store;
	int ret = 0, rooms = 0;

	for (auto i : intervals) {
		store.push_back(make_pair(i.start, 1));
		store.push_back(make_pair(i.end, -1));
	}

	sort(store.begin(), store.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first || (a.first == b.first && a.second < b.second);});

	for (auto i : store) {
		rooms += i.second;
		ret = max(ret, rooms);
	}

	return ret;
}

int main () {
	int i, n;
	Interval temp;
	vector<Interval> intervals;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Enter intervals (start, end) - \n";
	for (i = 0; i < n; i++) {
		cin >> temp.start >> temp.end;
		intervals.push_back(temp);
	}

	cout << "\n Minimum Number of conference rooms: " << minMeetingRooms(intervals);

	cout << "\n\n";
	return 0;
}
