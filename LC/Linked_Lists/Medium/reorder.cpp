/*

Given a singly linked list L: L0->L1->…->Ln-1->Ln,
reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
Given {1,2,3,4,5}, reorder it to {1,5,2,4,3}.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) // 850 ms
{
	if (!head || !head->next)
		return;

	ListNode *l1 = head, *temp = NULL, *l2 = NULL;

	while (l1)
	{
		l2 = l1;

		while (l2->next)
		{
			if (!l2->next->next)
				break;
			l2 = l2->next;
		}

		temp = l2->next;
		l2->next = NULL;

		if (temp)
		{
			temp->next = l1->next;
			l1->next = temp;
			l1 = temp->next;
		}

		else
			l1 = NULL;
	}
}

ListNode* reverseList(ListNode* head)
{
	ListNode *current = head, *next = NULL, *temp = NULL;

	while (current)
	{
		next = current->next;
		current->next = temp;
		temp = current;
		current = next;
	}

	return temp;
}

void reorderList2(ListNode* head)
{
	if (!head || !head->next || !head->next->next)
		return;

	ListNode *slow = head, *fast = head->next, *temp = NULL;

	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	fast = slow->next;
	slow->next = NULL;

	fast = reverseList(fast);

	slow = head;

	while (fast)
	{
		temp = fast->next;
		fast->next = slow->next;
		slow->next = fast;
		fast = temp;
		slow = slow->next->next;
	}
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

	reorderList2(head1);

	l1 = head1;

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
