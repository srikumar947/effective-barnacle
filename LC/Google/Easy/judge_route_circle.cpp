/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false

*/

#include <iostream>

using namespace std;

bool judgeCircle(string moves) {
	int x = 0, y = 0;
	for (char c : moves) {
		if (c == 'U')
			y += 1;
		else if (c == 'D')
			y -= 1;
		else if (c == 'L')
			x -= 1;
		else
			x += 1;
	}
	return x == 0 && y == 0;
}

int main () {
	string s;

	cout << "\n Enter string: ";
	cin >> s;

	cout << "\n The robot is going in circles: " << judgeCircle(s);

	cout << "\n\n";
	return 0;
}
