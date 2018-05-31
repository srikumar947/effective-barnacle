/*

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2

Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.

*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double largestTriangleArea(vector<vector<int> >& points);

double calArea(int xa, int ya, int xb, int yb, int xc, int yc);

int main()
{
	int n, x, y;
	vector<int> temp;
	vector<vector<int> > points;

	cout << "\n Enter number of points: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\n Enter Point " << i + 1 << " - ";
		cin >> x >> y;
		temp.push_back(x);
		temp.push_back(y);
		points.push_back(temp);
		temp.clear();
	}

	cout << "\n Area of Largest Triangle is " << largestTriangleArea(points) << "\n \n";

	return 0;
}

double largestTriangleArea(vector<vector<int> >& points) {
	double area = 0, temp = 0;

	for (vector<int> point1: points) {
		for (vector<int> point2: points) {
			for (vector<int> point3: points) {
				if ((point1 != point2) && (point1 != point3) && (point2 != point3)) {
					temp = calArea(point1[0], point1[1], point2[0], point2[1], point3[0], point3[1]);
					if (area < temp)
						area = temp;
				}
			}
		}
	}

	return area;
}

double calArea(int xa, int ya, int xb, int yb, int xc, int yc) {
	return 0.5 * fabs((xa * yb) + (xb * yc) + (xc * ya) - (xa * yc) - (xc * yb) - (xb * ya));
}
