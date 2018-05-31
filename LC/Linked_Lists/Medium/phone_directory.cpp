/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);

*/

#include <iostream>
#include <unordered_map>

using namespace std;

class PhoneDirectory {
public:
    unordered_map<int, int> map;
    int n;

    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        for (int i = 0; i < maxNumbers; i++)
            map[i] = 1;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (int i = 0; i < n; i++) {
            if (map[i] == 1) {
                map[i] = 0;
                return i;
            }
        }
        return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (map[number] == 1)
            return true;
        return false;
    }

    /** Recycle or release a number. */
    void release(int number) {
        map[number] = 1;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

int main () {
    int maxNumbers = 10, param_1;
    bool param_2;

    PhoneDirectory obj(maxNumbers);
    param_1 = obj.get();
    cout << "\n param_1: " << param_1;
    param_2 = obj.check(maxNumbers - param_1);
    cout << "\n param_2: " << param_2;
    obj.release(param_1);

    cout << "\n\n";

    return 0;
}
