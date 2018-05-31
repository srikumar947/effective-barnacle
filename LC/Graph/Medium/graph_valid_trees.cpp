/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

Tree is vaid if all the components are connected and there is no cycle.
This can be checked as follows -
1. Number of edges = Number of nodes - 1
2. Tree is acyclic (dfs)

If edges = n - 1, then there are two scenarios -
1. The edges don't form a cycle. In this case, the visit function will mark each node visited.
2. The edges form a cycle. In this case, the graph has to have at least 1 disconnected component. This component cannot be reached by the visit function.

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

bool validTree(int n, vector<pair<int, int>>& edges) {
    if (n == 0)
        return true;

    if (edges.size() != n - 1)
        return false;

    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);

    for (auto e: edges) {
        graph[e.first].push_back(e.second);
        graph[e.second].push_back(e.first);
    }

    visit(0, graph, visited);

    for (auto v : visited)
        if (v == 0)
            return false;

    return true;
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

    cout << "\n Tree is Valid: " << validTree(n, edges);

    cout << "\n\n";
    return 0;
}
