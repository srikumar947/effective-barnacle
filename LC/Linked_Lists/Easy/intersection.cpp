/*

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (headA == NULL || headB == NULL)
		return NULL;

	if (headA == headB)
		return headA;
	
	if (headA == headB->next)
		return headA;

	if (headB == headA->next)
		return headB;

	ListNode *l1 = headA, *l2 = headB;

	while (l1 != l2)
	{
		if (l1 == NULL)
			l1 = headB;
		else
			l1 = l1->next;

		if (l2 == NULL)
			l2 = headA;
		else
			l2 = l2->next;		
	}

	return l1;
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

	l1 = getIntersectionNode(head1, head1->next);

	if (l1)
		cout << "\n\n The intersection node is: " << l1->val << endl;
	else
		cout << "\n\n The intersection node is: NULL" << endl;

	return 0;
}