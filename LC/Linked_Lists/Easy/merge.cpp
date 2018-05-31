/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *l3 = NULL, *head3 = NULL;
	int flag = 1, x;

	while (l1 || l2)
	{
		if (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				x = l2->val;
				l2 = l2->next;
			}
			else
			{
				x = l1->val;
				l1 = l1->next;
			}

			ListNode* temp = new ListNode(x);

	        if (flag == 1)
	        {
	            head3 = temp;
	            l3 = temp;
	            flag = 0;
	        }

	        else
	        {
	            l3->next = temp;
	            l3 = temp;
	        }
		}

		else if (l1)
		{
			x = l1->val;
			l1 = l1->next;

			ListNode* temp = new ListNode(x);

	        if (flag == 1)
	        {
	            head3 = temp;
	            l3 = temp;
	            flag = 0;
	        }

	        else
	        {
	            l3->next = temp;
	            l3 = temp;
	        }
		}
		else if (l2)
		{
			x = l2->val;
			l2 = l2->next;

			ListNode* temp = new ListNode(x);

	        if (flag == 1)
	        {
	            head3 = temp;
	            l3 = temp;
	            flag = 0;
	        }

	        else
	        {
	            l3->next = temp;
	            l3 = temp;
	        }
		}
	}

	return head3;
}


int main()
{
	ListNode *l1 = NULL, *head1 = NULL, *l2 = NULL, *head2 = NULL;

	int i = 0, n, x, flag = 1, target;

	cout << "\n Enter the number of elements in first list: ";
	cin >> n;

	cout << "\n Enter the elements of the first list: ";

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

    i = 0;
    flag = 1;

    cout << "\n Enter the number of elements in second list: ";
	cin >> n;

	cout << "\n Enter the elements of the second list: ";

    while (i < n)
    {
    	cin >> x;

        ListNode* temp = new ListNode(x);

        if (flag == 1)
        {
            head2 = temp;
            l2 = temp;
            flag = 0;
        }

        else
        {
            l2->next = temp;
            l2 = temp;
        }

        i += 1;
    }

	l1 = mergeTwoLists(head1, head2);

	cout << "\n\n The new list is: ";

	while (l1)
	{
		if (l1->next != NULL)
			cout << l1->val << "->";
		else
			cout << l1->val;

		l1 = l1->next;
	}

	cout << endl;

	return 0;
}
