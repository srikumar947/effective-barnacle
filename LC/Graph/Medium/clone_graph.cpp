/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        if (map.find(node) == map.end()) {
            map[node] = new UndirectedGraphNode(node->label);
            for (auto n : node->neighbors) {
                map[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return map[node];
    }
};

// Attempted serializing and deserialzing a graph from a string. e.g. 0,1,2#1,2#2,2
/*
UndirectedGraphNode *buildGraph(string g) {
    int i = 0, n = g.size(), j = 0, k = 0, l = 0;
    vector<int> labels;
    vector<vector<int>> conns;
    vector<UndirectedGraphNode*> connections;

    for (i = 0; i < n; i++) {
        if (i == 0 || g[i - 1] == '#') {
            labels.push_back(g[i] - '0');
            connections.push_back(new UndirectedGraphNode(g[i] - '0'));
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0 || g[i - 1] == '#') {
            j = i + 1;
            for (k = 0; k < connections.size(); k++)
                if (connections[k]->label == g[i] - '0')
                    break;
            while (g[j] != '#' && j < n) {
                if (g[j] != ',') {
                    for (l = 0; l < connections.size(); l++)
                        if (connections[l]->label == g[j] - '0')
                            break;
                    connections[k]->neighbors.push_back(connections[l]);
                }
                j += 1;
            }
        }
    }

    return connections[0];
}

void bfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, int>& visited) {
    if (visited[node] != 1) {
        vector<UndirectedGraphNode*> connections;

        visited[node] = 1;
        cout << "\n Node " << node->label << ": ";

        if (node->neighbors.size() > 0) {
            for(auto n : node->neighbors) {
                cout << n->label << " ";
                connections.push_back(n);
            }
            for (auto c : connections)
                bfs(c, visited);
        }
    }
}

void print(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, int> visited;
    bfs(node, visited);
}

void clone(UndirectedGraphNode *node, string& g, unordered_map<UndirectedGraphNode*, int>& visited) {
    if (visited[node] != 1) {
        vector<UndirectedGraphNode*> connections;

        visited[node] = 1;
        g += to_string(node->label);

        if (node->neighbors.size() > 0) {
            for (auto n : node->neighbors) {
                g += "," + to_string(n->label);
                connections.push_back(n);
            }
        }

        g += "#";

        if (connections.size() > 0) {
            for (auto c : connections)
                clone(c, g, visited);
        }
    }
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node)
        return node;
    string g = "";
    unordered_map<UndirectedGraphNode*, int> visited;
    clone(node, g, visited);
    g.erase(g.end() - 1);
    UndirectedGraphNode *clone = buildGraph(g);
    return clone;
}


int main() {
    int i, n, x;
    string g;

    cout << "\n Enter the graph (Node1,link1,link2...#Node2,link1,...): ";
    cin >> g;

    UndirectedGraphNode *node = buildGraph(g);
    UndirectedGraphNode *clone = cloneGraph(node);
    print(clone);

    cout << "\n\n";
    return 0;
}
*/
