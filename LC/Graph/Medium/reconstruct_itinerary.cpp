/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void traverse(string location, map<string, multiset<string>>& target, vector<string>& path) {
    while (target[location].size()) {
        string next = *target[location].begin();
        target[location].erase(target[location].begin());
        traverse(next, target, path);
    }
    path.push_back(location);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    map<string, multiset<string>> target;
    vector<string> path;

    for (auto p : tickets)
        target[p.first].insert(p.second);
    traverse("JFK", target, path);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<pair<string, string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> ret = findItinerary(tickets);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << "\n\n";
    return 0;
}
