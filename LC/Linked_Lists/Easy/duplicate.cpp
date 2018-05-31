/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	int flag;
	ListNode *l1 = head;
	
	while (head)
	{
		flag = 0;
		
		if (head->next)
		{
			if (head->next->val == head->val)
				{
					ListNode *temp = head->next;
					head->next = head->next->next;
					delete (temp);
					flag = 1;
				}
		}

		if (flag == 0)
			head = head->next;
	}

	return l1;
}


int main()
{
	ListNode *l1, *head1;

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

	l1 = deleteDuplicates(head1);

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