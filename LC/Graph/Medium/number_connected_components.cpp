/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Follows same logic as valid tree.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void visit(int node, vector<vector<int>>& graph, vector<int>& visited) {
    if (visited[node])
        return;

    visited[node] = 1;

    for (auto n : graph[node])
        visit(n, graph, visited);
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    if (n == 0)
        return 0;

    if (edges.size() < 1)
        return n;

    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);
    int count = 0;

    for (auto e: edges) {
        graph[e.first].push_back(e.second);
        graph[e.second].push_back(e.first);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            visit(i, graph, visited);
            count += 1;
        }
    }

    return count;
}

int main() {
    vector<pair<int, int>> edges;
    pair<int, int> temp;
    int i, n, m, x, y;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter number of edges: ";
    cin >> m;

    cout << "\n Enter the edges: ";
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        temp.first = x;
        temp.second = y;
        edges.push_back(temp);
    }

    cout << "\n Number of connected components: " << countComponents(n, edges);

    cout << "\n\n";
    return 0;
}
