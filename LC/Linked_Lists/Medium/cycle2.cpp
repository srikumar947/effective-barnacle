/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *findBeg(ListNode *head, ListNode *node) // 39 ms
{
	ListNode *p = head, *q = NULL, *ret = NULL;

	while (p)
	{
		if (p == node)
			return p;

		q = node->next;

		while (q != node)
		{
			if (p == q)
				return p;

			q = q->next;
		}

		p = p->next;
	}
}

ListNode *findBeg2(ListNode *head, ListNode *node) // 9 ms
{
	ListNode *p = head, *q = node, *ret = NULL;

	while (p != q)
	{
		q = q->next;
		p = p->next;
	}

	return q;
}

ListNode *detectCycle(ListNode *head)
{
	if (!head || !head->next)
		return NULL;

	ListNode *p = head, *q = head;

	while (p || q)
	{
		p = p->next;
		q = q->next;

		if (q)
		{
			if (q->next)
				q = q->next;
			else
				return NULL;
		}

		else
			return NULL;

		if (p == q)
			return findBeg2(head, p);
	}

	return NULL;
}

ListNode *detectCycle2(ListNode *head) {
	if (!head || !head->next)
		return NULL;

	ListNode *slow = head, *fast = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			slow = head;
			while (slow != fast){
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}

	return NULL;
}

int main()
{
	ListNode *l1 = NULL, *head1 = NULL;

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

    if (l1 && head1->next)
    	l1->next = head1->next->next;

    l1 = detectCycle(head1);

    if (l1)
		cout << "\n The list contains a cycle and begins at: " << l1->val;
	else
		cout << "\n The list doesn't contain a cycle.";

	cout << endl;

	return 0;
}
