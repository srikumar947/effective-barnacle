/*

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

Sort the array based on height in decreasing order.
Sort the max height people based on their k value.
For all other people just insert them at their k value in return vector.

sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);});
This will implement the sorting as needed as quickly as possible. It gives 38 ms vs 96 ms for sort1()
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void sort1(vector<pair<int, int> >& people) {
	int temp;
	for (int i = 0; i < people.size(); i++) {
		for (int j = 0; j < people.size(); j++) {
			if (i != j) {
				if (people[i].first > people[j].first) {
					temp = people[i].first;
					people[i].first = people[j].first;
					people[j].first = temp;

					temp = people[i].second;
					people[i].second = people[j].second;
					people[j].second = temp;
				}
			}
		}
	}

	for (int i = 0; i < people.size(); i++) {
		for (int j = 0; j < people.size(); j++) {
			if ((i != j) && (people[i].first == people[j].first)) {
				if (people[i].second < people[j].second) {
					temp = people[i].second;
					people[i].second = people[j].second;
					people[j].second = temp;
				}
			}
		}
	}
}

vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
	vector<pair<int, int> > ret;
	sort1(people);

	for (int i = 0; i < people.size(); i++) {
		ret.insert(ret.begin() + people[i].second, people[i]);
	}

	return ret;
}

int main() {
	vector<pair<int, int> > people;
	pair<int, int> g;
	int n, h, k;

	cout << "\n Enter number of people: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\n Enter (h, k) for person " << i + 1 << " - ";
		cin >> h >> k;
		g.first = h;
		g.second = k;
		people.push_back(g);
	}

	people = reconstructQueue(people);

	cout << "\n Reconstructed Queue is - \n ";

	for (int i = 0; i < people.size(); i++) {
		cout << "(" << people[i].first << ", " << people[i].second << ")\n ";
	}

	cout << "\n\n";

	return 0;
}
