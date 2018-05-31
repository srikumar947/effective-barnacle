/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].

We can solve it using graph coloring.
We start coloring an uncolored root node with 1, and start the DFS, where if a node is colored 1, all its neighbors are colored -1 and vice versa.
If a node encounters its neighbor that has already been colored with the same color, then the graph isn't bipartite.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool dfs(int node, int current_color, vector<vector<int>>& graph, vector<int>& color) {
    if (color[node] != 0)
        return color[node] == current_color;        // If node is already colored, check the color. If current color is -1 and node is colored 1, return false. i.e. the node was colored by some other node for a conflicting color.

    color[node] = current_color;

    for (auto n : graph[node]) {
        if (!dfs(n, -current_color, graph, color))
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), 0);         // All nodes are uncolored

    for (int i = 0; i < graph.size(); i++)
        if (color[i] == 0)                      // If node is uncolored
            if(!dfs(i, 1, graph, color))       // Give it a color and call DFS
                return false;

    return true;
}

int main() {
    vector<vector<int>> graph = {{1,3}, {0,2}, {1,3}, {0,2}};

    cout << "\n Graph is Bipartite: " << isBipartite(graph);

    cout << "\n\n";
    return 0;
}
