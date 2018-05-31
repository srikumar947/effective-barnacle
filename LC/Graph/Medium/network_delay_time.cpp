/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

Use Bellman Ford
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> distance(N + 1, INT_MAX);
    distance[K] = 0;
    for (int i = 0; i < N; i++) {
        for (auto t : times) {
            int u = t[0], v = t[1], w = t[2];
            if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
                distance[v] = distance[u] + w;
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        ret = max(ret, distance[i]);
    }
    return ret == INT_MAX ? -1 : ret;
}

int main() {
    vector<vector<int>> times;
    vector<int> temp;
    int i, n, m, x, y, z, k;

    cout << "\n Enter (n, k): ";
    cin >> n >> k;

    cout << "\n Enter number of times: ";
    cin >> m;

    cout << "\n Enter the times: ";
    for (i = 0; i < m; i++) {
        cin >> x >> y >> z;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        times.push_back(temp);
        temp.clear();
    }

    int ret = networkDelayTime(times, n, k);

    cout << "\n Network Delay Time: " << ret;

    cout << "\n\n";
    return 0;
}
