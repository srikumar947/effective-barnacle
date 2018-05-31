/*
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]

Node i connections = graph[i]

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].

[[], [0,2,3,4], [3], [4], []]
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, unordered_set<int>& cycle_nodes, unordered_set<int>& safe_nodes, unordered_set<int>& visited) {
    if (cycle_nodes.find(node) != cycle_nodes.end())
        return false;

    if (safe_nodes.find(node) != safe_nodes.end())
        return true;

    if (visited.find(node) != visited.end()) {
        cycle_nodes.insert(node);
        return false;
    }

    visited.insert(node);

    for (auto g : graph[node]) {
        if (!isSafe(g, graph, cycle_nodes, safe_nodes, visited)) {
            cycle_nodes.insert(node);
            return false;
        }
    }

    safe_nodes.insert(node);
    return true;

}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ret;
    if (!graph.size())
        return ret;

    unordered_set<int> visited, cycle_nodes, safe_nodes;

    for (int i = 0; i < graph.size(); i++) {
        if(isSafe(i,graph, cycle_nodes, safe_nodes, visited))
            ret.push_back(i);
    }

    return ret;
}

int main() {
    vector<vector<int>> graph;
    vector<int> temp;
    int i, j, n, m, x;

    cout << "\n Enter number of nodes: ";
    cin >> m;

    for (i = 0; i < m; i++) {
        cout << "\n Enter the number of connections for Node " << i << ": ";
        cin >> n;
        cout << "\n Enter the connections for Node " << i << ": ";
        for (j = 0; j < n; j++) {
            cin >> x;
            temp.push_back(x);
        }
        graph.push_back(temp);
        temp.clear();
    }

    vector<int> ret = eventualSafeNodes(graph);

    cout << "\n Safe States: ";
    for (i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }

    cout << "\n\n";
    return 0;
}
