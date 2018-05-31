/*

Sort a linked list using insertion sort.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head)
{
	if (!head || !head->next)
		return head;

	ListNode *l1 = head, *l2 = NULL, *current = NULL, *temp;

	while (l1)
	{
		current = l1;
		l1 = l1->next;

		if (l2 == NULL || current->val < l2->val) // If sorted list is empty or the current node's value is less than the least element in sorted list.
		{
			current->next = l2;
			l2 = current;
		}

		else
		{
			temp = l2;
			
			while (temp)
			{
				if (temp->next == NULL || temp->next->val > current->val) // If you've reached the last element in the sorted list or found the correct position for the node.
				{
					current->next = temp->next;
					temp->next = current;
					break;
				}

				temp = temp->next;
			}
		}

	}

	return l2;
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

	l1 = insertionSortList(head1);

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