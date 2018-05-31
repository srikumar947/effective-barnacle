/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd2(ListNode* head, int n) {
	ListNode *l = head;
	int i, m = 0;

	while (l) {
		l = l->next;
		m += 1;
	}

	if (m == n)
		return head->next;

	l = head;

	for (i = 0; i < m - n - 1; i++)
		l = l->next;

	l->next = l->next->next;
	return head;
}

// One Pass. Move first pointer by n places. Then move both pointers simultaneously until first reaches NULL. Then unlink second->next.
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *first = head, *second = NULL;
	int i = 0;

	while (i < n) {
		first = first->next;
		i += 1;
	}

	while (first) {
		first = first->next;
		if (second)
			second = second->next;
		else
			second = head;
	}

	if (second)
		second->next = second->next->next;
	else
		head = head->next;
	return head;
}

int main()
{
	ListNode *l1, *head1, *l2;

	int i = 0, n, x, flag = 1, target;

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

    cout << "\n Enter the Nth Node from end: ";
    cin >> target;

	l2 = removeNthFromEnd(head1, target);

	cout << "\n\n The new list is: ";

	while (l2)
	{
		if (l2->next != NULL)
			cout << l2->val << "->";
		else
			cout << l2->val;

		l2 = l2->next;
	}

	cout << endl;

	return 0;
}
