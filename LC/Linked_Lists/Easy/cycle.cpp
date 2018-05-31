/*
Given a linked list, determine if it has a cycle in it.

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

bool hasCycle(ListNode *head) {
	ListNode *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
			return true;
    }

    return false;
}

bool hasCycle2(ListNode *head)
{
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
				return false;
		}

		else
			return false;

		if (p == q)
			return true;
	}
	return false;
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

    l1->next = head1->next;

    if (hasCycle(head1) == 0)
		cout << "\n The list doesn't contain a cycle.";
	else
		cout << "\n The list contains a cycle.";

	cout << endl;

	return 0;
}
