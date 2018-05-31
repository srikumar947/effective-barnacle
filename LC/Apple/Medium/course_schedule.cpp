/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

Hints:

This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses);
    vector<int> inDegree(numCourses);
    int i = 0, j = 0;

    for (auto p : prerequisites) {
            graph[p.second].insert(p.first);
            inDegree[p.first]++;
    }

    for (i = 0; i < numCourses; i++) {
        for (j = 0; j < numCourses; j++)
            if (!inDegree[j])
                break;
        if (j == numCourses)
            return false;

        inDegree[j] = -1;

        for (auto p : graph[j])
            inDegree[p]--;
    }
    return true;
}

int main() {
    vector<pair<int, int>> prerequisites;
    pair<int, int> temp;
    int i, n, m, x, y;

    cout << "\n Enter number of courses: ";
    cin >> n;

    cout << "\n Enter number of pairs: ";
    cin >> m;

    cout << "\n Enter the paris: ";
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        temp.first = x;
        temp.second = y;
        prerequisites.push_back(temp);
    }

    cout << "\n Courses can be finished: " << canFinish(n, prerequisites);

    cout << "\n\n";
    return 0;
}
