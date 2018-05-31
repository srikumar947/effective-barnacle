/*

Sort a linked list in O(n log n) time using constant space complexity.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode *l1, ListNode *l2) {
	if (!l1 && !l2)
		return NULL;

	if (!l1)
		return l2;

	if (!l2)
		return l1;

	ListNode *head = NULL, *current = NULL;

	if (l1->val < l2->val) {
		head = l1;
		current = head;
		l1 = l1->next;
	}
	else {
		head = l2;
		current = head;
		l2 = l2->next;
	}

	while (l1 || l2) {
		if (l1 && l2) {
			if (l1->val < l2->val) {
				current->next = l1;
				current = l1;
				l1 = l1->next;
			}
			else {
				current->next = l2;
				current = l2;
				l2 = l2->next;
			}
		}
		else if (l1) {
			current->next = l1;
			current = l1;
			l1 = l1->next;
		}
		else if (l2) {
			current->next = l2;
			current = l2;
			l2 = l2->next;
		}
	}

	return head;
}

ListNode* sortList(ListNode* head) {
	if (!head || !head->next)
		return head;

	ListNode *start = head, *mid = NULL, *slow = head, *fast = head->next;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	mid = slow->next;
	slow->next = NULL;


	slow = sortList(start);
	fast = sortList(mid);

	return merge(slow, fast);
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

	l1 = sortList(head1);

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
