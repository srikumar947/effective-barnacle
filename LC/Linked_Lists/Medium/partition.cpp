/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode *current = NULL, *l = head, *next = NULL, *small = NULL, *big = NULL, *smallHead = NULL, *bigHead = NULL;
	while (l) {
		current = l;
		l = l->next;

		if (current->val < x) {
			if (!small) {
				smallHead = current;
				smallHead->next = NULL;
				small = smallHead;
			}
			else {
				small->next = current;
				small = current;
				small->next = NULL;
			}
		}
		else {
			if (!big) {
				bigHead = current;
				bigHead->next = NULL;
				big = bigHead;
			}
			else {
				big->next = current;
				big = current;
				big->next = NULL;
			}
		}
	}
	if (small)
		small->next = bigHead;
	else
		smallHead = bigHead;

	return smallHead;
}

int main()
{
	ListNode *l1 = NULL, *head1 = NULL;

	int i = 0, n, x, flag = 1;

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

    cout << "\n Enter the partition value: ";
    cin >> x;

	l1 = partition(head1, x);

	if (l1)
	{
		cout << "\n\n The new list is: ";

		while (l1)
		{
			if (l1->next != NULL)
				cout << l1->val << "->";
			else
				cout << l1->val;

			l1 = l1->next;
		}
	}

	else
		cout << "\n Empty list";

	cout << endl;

	return 0;
}
