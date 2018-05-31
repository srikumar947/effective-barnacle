/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (!head || !head->next || m == n )
		return head;
	
	int i = 1, flag = 1;

	ListNode *l = head, *before = NULL, *start = NULL, *temp = NULL, *current = NULL, *next = NULL;

	if (m == 1)
	{
		start = head;
		before = NULL;
	}

	else
	{
		while (i < m - 1)
		{
			l = l->next;
			i += 1;
		}

		start = l->next;
		before = l;
	}

	current = start;
	l = start;
	i = 1;

	while (i <= n - m + 1)
	{
		l = l->next;
		next = current->next;
		current->next = temp;
		temp = current;
		current = next;
		i += 1;
	}

	if (before)	
		before->next = temp;
	else
		before = temp;

	start->next = l;
	
	if (m == 1)
		return before;
	else
		return head;
}

int main()
{
	ListNode *l1 = NULL, *head1 = NULL;

	int i = 0, n, x, flag = 1, m;

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

    cout << "\n Enter m (>= 1 and <= len): ";
    cin >> m;

    cout << "\n Enter n (>= m and <= len): ";
    cin >> n;

	l1 = reverseBetween(head1, m, n);

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