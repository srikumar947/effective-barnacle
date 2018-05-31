/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

0 0
94911151 94911150
94911152 94911151
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int maxPoints(vector<Point>& points) {
    if (points.size() < 1)
        return 0;

    if (points.size() == 1)
        return 1;

    int ret = 0, duplicate, i, j, n = points.size(), dx, dy, divisor;
    unordered_map<int, unordered_map<int, int>> slopes;

    for (i = 0; i < n; i++) {
        duplicate = 1;
        slopes.clear();

        for (j = i + 1; j < n; j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                duplicate += 1;
                continue;
            }

            dx = points[i].x - points[j].x;
            dy = points[i].y - points[j].y;

            divisor = gcd(dx, dy);

            if (divisor != 0) {
                dx = dx/divisor;
                dy = dy/divisor;
            }

            if (slopes.find(dx) != slopes.end()) {
                if (slopes[dx].find(dy) != slopes[dx].end())
                    slopes[dx][dy] += 1;
                else
                    slopes[dx][dy] = 1;
            }
            else
                slopes[dx][dy] = 1;
        }

        ret = max(ret, duplicate);

        auto it = slopes.begin();
        while (it != slopes.end()) {
            auto it2 = it->second.begin();
            while (it2 != it->second.end()) {
                if (it2->second + duplicate > ret)
                    ret = it2->second + duplicate;
                it2++;
            }
            it++;
        }
    }
    return ret;
}

int main() {
    vector<Point> points;
    int n, i, x, y;

    cout << "\n Enter n: ";
    cin >> n;

    cout << "\n Enter Points: \n";
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        Point temp(x, y);
        points.push_back(temp);
    }

    cout << "\n Max number of Points: " << maxPoints(points);

    cout << "\n\n";
    return 0;
}
