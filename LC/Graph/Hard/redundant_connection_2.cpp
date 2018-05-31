/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

[[2,1],[3,1],[4,2],[1,4]]
1 <- 2
|  ^
v /  \
4    3

  3 >> 1 >> 4
       ^    v
       ^    v
       2 < <

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

bool isTree(vector<vector<int>>& graph) {
    unordered_set<int> visited, cycle_nodes, safe_nodes;
    int flag = 0;

    for (int i = 1; i < graph.size(); i++, flag = 0) {

        if (!isSafe(i, graph, cycle_nodes, safe_nodes, visited))
            break;

        for (int j = 1; j < graph.size(); j++)
            if (visited.count(j) == 0)
                flag = 1;

        if (flag == 0)
            return true;
    }

    return false;
}

bool notReachable(vector<int>& inDegrees) {
    int count = 0;
    for (int i = 1; i < inDegrees.size(); i++)
        if (inDegrees[i] == 0)
            count += 1;
    if (count > 1)
        return true;
    return false;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> ret;

    for (int i = edges.size() - 1; i >= 0; i--) {
        vector<vector<int>> graph(edges.size() + 1, vector<int>{});
        vector<int> inDegrees(edges.size() + 1, 0);

        for (int j = edges.size() - 1; j >= 0; j--) {
            if (i != j) {
                graph[edges[j][0]].push_back(edges[j][1]);
                inDegrees[edges[j][1]]++;
            }
        }

        if (notReachable(inDegrees))
            continue;

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

    vector<int> ret = findRedundantDirectedConnection(edges);
    cout << "\n Redundant Connection: ";
    for (i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";

    cout << "\n\n";
    return 0;
}

/* Time Limit Exceeded. Works perfectly though.
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
    int flag = 0;

    for (int i = 1; i < visited.size(); i++, flag = 0) {
        fill(visited.begin(), visited.end(), 0);

        if (hasCycle(i, -1, graph, visited))
            flag = 1;

        for (int j = 1; j < visited.size(); j++)
            if (visited[j] == 0)
                flag = 1;

        if (flag == 0)
            return true;
    }

    return false;
}
*/
