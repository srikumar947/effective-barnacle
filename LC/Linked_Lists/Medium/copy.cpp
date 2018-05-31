/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
	if (!head)
		return NULL;

	RandomListNode *l = head, *temp = NULL, *newL = NULL, *newHead = NULL;
	int flag = 1;

	while(l)
	{
		RandomListNode *copy = new RandomListNode(l->label);
		copy->next = l->next;
		copy->random = l->random;
		l->next = copy;
		l = copy->next;
	}

	l = head;

	while (l)
	{
		if (l->random)
			l->next->random = l->random->next;
		else
			l->next->random = NULL;

		l = l->next->next;
	}

	l = head;

	while(l)
	{
		newL = l->next;
		temp = newL->next;
		
		if (temp)
			newL->next = temp->next;
		else
			newL->next = NULL;

		l->next = temp;
		l = temp;
		
		if (flag)
		{
			newHead = newL;
			flag = 0;
		}
	}

	return newHead;
}

int main()
{
	RandomListNode *l1 = NULL, *head1 = NULL, *l2 = NULL;

	int i = 0, n, x, flag = 1;

	cout << "\n Enter the number of elements: ";
	cin >> n;
	
	cout << "\n Enter the elements: ";

	while (i < n)
    {
    	cin >> x;

        RandomListNode* temp = new RandomListNode(x);
        
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

    l1 = head1;
    l1->random = l1;

    l1 = head1->next;
    //l1->random = l1;

    l1 = head1;
	l2 = copyRandomList(head1);

	if (l1)
	{
		cout << "\n\n The old list is: ";
	
		while (l1)
		{
			if (l1->next != NULL)
				cout << l1->random << "->";
			else
				cout << l1->random;

			l1 = l1->next;
		}
	}
	
	else
		cout << "\n\n Empty list";


	if (l2)
	{
		cout << "\n\n The new list is: ";
	
		while (l2)
		{
			if (l2->next != NULL)
				cout << l2->random << "->";
			else
				cout << l2->random;

			l2 = l2->next;
		}
	}
	
	else
		cout << "\n\n Empty list";

	cout << endl;

	return 0;
}