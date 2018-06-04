/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int picked;

int guess(int num) {
	if (num > picked)
		return -1;
	else if (num < picked)
		return 1;
	return 0;
}

// Do Not use (max + min)/2 in case of overflow

int guessNumber(int n) {
	int max = n, min = 1;
    while (true) {
        int mid = ((max - min) / 2) + min;
        int temp = guess(mid);
		if (!temp)
            return mid;
        else if (temp == 1)
            min = mid + 1;
		else
            max = mid - 1;
    }
}

int main () {
	int n;

	cout << "\n Enter picked number: ";
	cin >> picked;

	cout << "\n Enter n: ";
	cin >> n;

	cout << "\n Picked Number: " << guessNumber(n);

	cout << "\n\n";
	return 0;
}
