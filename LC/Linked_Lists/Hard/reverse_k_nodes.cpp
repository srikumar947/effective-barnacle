/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode *current = head, *next = NULL, *previous = NULL;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k < 1)
        return NULL;

    if (k == 1)
        return head;

    ListNode *l = head, *next = NULL, *previous = NULL, *end = NULL, *temp = NULL, *start = NULL;
    int i = 1, flag = 1;

    while (l) {
        i = 1;
        while (i < k) {
            if (i == 1)
                start = l;
            if (l)
                l = l->next;
            else
                return head;
            i += 1;
        }

        if (!l)
            return head;

        end = l;
        l = l->next;
        end->next = NULL;

        temp = reverseList(start);

        if (flag) {
            head = temp;
            flag = 0;
        }

        else
            previous->next = temp;

        while (temp->next) {
            temp = temp->next;
        }

        previous = temp;
        temp->next = l;
    }

    return head;
}


int main()
{
	ListNode *l1 = NULL, *head1 = NULL;

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

	l1 = reverseKGroup(head1, k);

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
		cout << "\n\n Empty list";

	cout << endl;

	return 0;
}
