/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
	if (head == NULL)
		return NULL;

	ListNode *l = head, *current = NULL, *temp = NULL, *previous = NULL;
	int flag = 1, flag2 = 1;

	current = head;

	while (current && current->next)
	{
		temp = current->next;
		current->next = temp->next;
		temp->next = current;

		if (previous)
			previous->next = temp;
		
		if (flag == 1)
		{
			head = temp;
			flag = 0;
		}

		previous = current;
		current = current->next;
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

	l1 = swapPairs(head1);

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
		cout << "\n Empty list";
	
	cout << endl;

	return 0;
}