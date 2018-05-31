/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates2(ListNode* head) {
	if (!head || !head->next)
		return head;

	ListNode *l = head, *current = NULL, *previous = NULL;

	while (l->next) {
		if (l->val == l->next->val) {
			current = l;
			while (current->next && (current->val == current->next->val)) {
				current = current->next;
			}
			if (previous)
				previous->next = current->next;
			else
				head = current->next;

			l = current->next;
		}
		else {
			previous = l;
			l = l->next;
		}

		if (l == NULL)
			break;
	}
	return head;
}

ListNode* deleteDuplicates(ListNode* head)
{
	if (!head || !head->next)
		return head;

	unordered_map <int, int> map;
	int flag = 0;
	ListNode *l = head;

	while (l)
	{
		if (map[l->val])
			map[l->val] += 1;

		else
			map[l->val] = 1;

		l = l->next;
	}

	l = head;

	while (l)
	{
		flag = 0;

		if (map[l->val] > 1 && l == head)
		{
			head = head->next;
			l = head;
			flag = 1;
		}

		if (l && l->next)
		{
			if (map[l->next->val] > 1)
			{
				l->next = l->next->next;
				flag = 1;
			}
		}

		if (!flag)
			l = l->next;
	}

	return head;
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

	l1 = deleteDuplicates(head1);

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
