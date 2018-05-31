/*

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head)
{
	if (head == NULL)
		return NULL;

	ListNode *odd = NULL, *even = NULL, *l = head, *oddhead = NULL, *evenhead = NULL;
	int i = 1;
	
	while (l)
	{
		if (i % 2 == 0)
		{
			if (i == 2)
			{
				evenhead = l;
				even = l;
			}
			else
			{
				even->next = l;
				even = l;	
			}
		}

		else
		{
			if (i == 1)
			{
				oddhead = l;
				odd = l;
			}
			else
			{
				odd->next = l;
				odd = l;	
			}	
		}

		i += 1;
		l = l->next;
	}

	if (even)
		even->next = NULL;

	if (odd)
		odd->next = NULL;
	
	odd = oddhead;

	while (odd->next)
		odd = odd->next;

	odd->next = evenhead;

	return oddhead;
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

	l1 = oddEvenList(head1);

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