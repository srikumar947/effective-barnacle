/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool hasCycle(int node, int parent, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;

    for (auto n : graph[node]) {
        if (!visited[n]) {
            if (hasCycle(n, node, graph, visited))
                return true;
        }
        else if (n != parent)
            return true;
    }

    return false;
}

bool isTree(vector<vector<int>>& graph) {
    vector<int> visited(graph.size(), 0);

    if (hasCycle(1, -1, graph, visited))
        return false;

    for (int i = 1; i < graph.size(); i++)
        if (visited[i] == 0)
            return false;
    return true;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ret;

    for (int i = edges.size() - 1; i >= 0; i--) {
        vector<vector<int>> graph(edges.size() + 1, vector<int>{});

        for (int j = edges.size() - 1; j >= 0; j--) {
            if (i != j) {
                graph[edges[j][0]].push_back(edges[j][1]);
                graph[edges[j][1]].push_back(edges[j][0]);
            }
        }

        if (isTree(graph))
            return edges[i];
    }
    return ret;
}

int main() {
    vector<vector<int>> edges;
    vector<int> temp;
    int i, m, x, y;

    cout << "\n Enter number of edges: ";
    cin >> m;

    cout << "\n Enter the edges: ";
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
        temp.clear();
    }

    vector<int> ret = findRedundantConnection(edges);
    cout << "\n Redundant Connection: ";
    for (i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";

    cout << "\n\n";
    return 0;
}
