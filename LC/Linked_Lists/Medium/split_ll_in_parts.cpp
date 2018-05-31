/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].

*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
	vector<ListNode *> ret(k, NULL);
	ListNode *l = root, *next = NULL, *head = NULL;
	int n = 0, i = 0, j = 0, chunk = 0, leftover = 0, size = 0;

	while (l) {
		n += 1;
		l = l->next;
	}

	l = root;

	chunk = n / k;
	leftover = n % k;

	for (i = 0; i < k; i++) {
		if (l) {
			if (leftover > 0)
				size = chunk + 1;
			else
				size = chunk;

			leftover -= 1;

			head = l;

			for (j = 0; j < size - 1; j++)
				l = l->next;

			next = l->next;
			l->next = NULL;
			l = next;

			ret[i] = head;
		}
	}

	return ret;
}

int main()
{
	ListNode *l1 = NULL, *head1 = NULL;
	vector<ListNode *> ret;
	int i = 0, n, x, flag = 1, k;

	cout << "\n Enter the number of elements: ";
	cin >> n;

	cout << "\n Enter the elements: ";

	while (i < n)
    {
    	cin >> x;

        ListNode* temp = new ListNode(x);

        if (flag == 1)
        {
            head1 = temp;
            l1 = temp;
            flag = 0;
        }

        else
        {
            l1->next = temp;
            l1 = temp;
        }

        i += 1;
    }

	cout << "\n Enter k: ";
	cin >> k;

	ret = splitListToParts(head1, k);

	if (ret.size() > 0) {
		cout << "\n\n The new list is: ";

		for (i = 0; i < ret.size(); i++) {
			cout << "\n ";
			l1 = ret[i];
			if (l1 == NULL)
				cout <<"NULL";

			while (l1) {
				if (l1->next != NULL)
					cout << l1->val << "->";
				else
					cout << l1->val;

				l1 = l1->next;
			}
		}
	}

	else
		cout << "\n Empty list";

	cout << endl;

	return 0;
}
