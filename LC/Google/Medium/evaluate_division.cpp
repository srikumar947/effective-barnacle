/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

double dfs(string num, string den, unordered_map<string, unordered_map<string, double>>& map, unordered_set<string>& visited) {
    if (map[num].find(den) != map[num].end())
        return map[num][den];

    for (auto it : map[num]) {
        if (!visited.count(it.first)) {
            visited.insert(it.first);
            double temp = dfs(it.first, den, map, visited);
            if (temp)
                return temp * it.second;
        }
    }

    return 0;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map<string, unordered_map<string, double>> map;
    vector<double> ret;

    string temp;
    int i;
    double val;

    for (i = 0; i < values.size(); i++) {
        map[equations[i].first].insert(make_pair(equations[i].second, values[i]));          // a / b

        map[equations[i].first].insert(make_pair(equations[i].first, 1.0));                 // a / a
        map[equations[i].second].insert(make_pair(equations[i].second, 1.0));               // b / b

        if (values[i] != 0)
            map[equations[i].second].insert(make_pair(equations[i].first, 1/values[i]));    // b / a
    }

    for (auto pair : queries) {
        if (map.find(pair.first) == map.end() || map.find(pair.second) == map.end())
            ret.push_back(-1.0);
        else {
            unordered_set<string> visited;
            val = dfs(pair.first, pair.second, map, visited);
            if (val)
                ret.push_back(val);
            else
                ret.push_back(-1.0);
        }
    }
    return ret;
}

int main () {
    vector<pair<string, string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> ret = calcEquation(equations, values, queries);

    cout << "\n Values: ";
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";

    cout << "\n\n";
}
