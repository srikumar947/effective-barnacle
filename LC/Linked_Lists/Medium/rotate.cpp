/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* rotateRight2(ListNode* head, int k) {
	if (head == NULL || k < 0)
		return NULL;

	if(head->next == NULL)
		return head;

	int i, n = 0;
	ListNode *l = head, *next = NULL, *newHead = NULL;

	while (l) {
		n += 1;
		l = l->next;
	}

	k = k % n;

	if (k == 0 || k == n)
		return head;

	l = head;

	for (i = 0; i < n - k - 1; i++)
		l = l->next;

	next = l->next;
	l->next = NULL;

	newHead = next;

	while (next) {
		if (next->next == NULL) {
			next->next = head;
			break;
		}
		next = next->next;
	}
	return newHead;
}

ListNode* rotateRight(ListNode* head, int k)
{
	if(!head)
		return head;

    int n = 1, i = 0;

    ListNode *l1 = head, *l2 = head;

    while(l2->next)
    {
        l2 = l2->next;
        n += 1;
    }

    l2->next = head;

    if(k %= n)
    {
        while(i < n - k)
    	{
    		l2 = l2->next;
    		i += 1;
    	}
    }

    l1 = l2->next;
    l2->next = NULL;

    return l1;
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

    cout << "\n Enter k: ";
    cin >>x;

	l1 = rotateRight(head1, x);

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
