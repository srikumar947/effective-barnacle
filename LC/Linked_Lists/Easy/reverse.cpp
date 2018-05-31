/*
Reverse a singly linked list.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList2(ListNode* head) // 30 ms
{
	ListNode *l1 = head, *start = head, *mid = NULL;
	int i = 1, m = 0, flag = 1, len, k, temp;
	float check, j;

	while (l1)
	{
		m += 1;

		if (flag == 1)
		{
			mid = l1;
			j = 1.0;
			flag = 0;
		}

		check = float(m) / 2.0;

		if (check > j)
		{
			mid = mid->next;
			j += 1.0;
		}

		if (l1->next == NULL)
		{
			temp = l1->val;
			l1->val = start->val;
			start->val = temp;
			start = start->next;
		}

		l1 = l1->next;
	}


	len = m / 2;

	while (len > 1)
	{
		l1 = mid;
		k = 1;

		while (k < len)
		{
			l1 = l1->next;
			k += 1;
		}

		temp = l1->val;
		l1->val = start->val;
		start->val = temp;

		start = start->next;
		len -= 1;
	}

	return head;
}

// Unlink your first element and move on to your second. Link the second to first element - second->next = first and continue for all nodes. 6ms
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

int main() {
	ListNode *head = NULL, *l = NULL;
	int flag = 1, n, x, i;

	cout << "\n Enter number of elements: ";
	cin >> n;

	cout << "\n Enter elements: ";

	for (i = 0; i < n; i++) {
		cin >> x;
		ListNode *temp = new ListNode(x);
		if (flag == 1) {
			head = temp;
			l = head;
			flag = 0;
		}
		else {
			l->next = temp;
			l = temp;
		}
	}

	head = reverseList(head);

	l = head;
	cout << "\n The list is: ";
	while (l) {
		cout << l->val << " ";
		l = l->next;
	}

	cout << "\n\n";
	return 0;
}
