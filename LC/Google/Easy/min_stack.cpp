/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

Your MinStack object will be instantiated and called as such:
MinStack obj = new MinStack();
obj.push(x);
obj.pop();
int param_3 = obj.top();
int param_4 = obj.getMin();
*/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
	vector<int> minVal;
	vector<int> st;

    void push(int x) {
		st.push_back(x);
		if (minVal.size() == 0 || getMin() >= x)
			minVal.push_back(x);
    }

    void pop() {
		if (st.back() == minVal.back())
			minVal.pop_back();
		st.pop_back();
    }

    int top() {
		return st.back();
    }

    int getMin() {
		return minVal.back();
    }
};

int main () {
	MinStack obj;
	obj.push(-3);
	obj.push(-2);
	cout << obj.top();
	cout << obj.getMin();
	obj.pop();

	cout << "\n\n";
	return 0;
}
