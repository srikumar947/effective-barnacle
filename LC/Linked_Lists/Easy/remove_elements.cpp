/*

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val)
{
	int flag ;
	ListNode *l1 = head;

	while (l1)
	{
		flag = 0;

		if (head->val == val)
		{
			head = head->next;
			l1 = head;
			flag = 1;
		}

		else if (l1->next && l1->next->val == val)
		{
			l1->next = l1->next->next;
			flag = 1;
		}

		if (flag == 0)
			l1 = l1->next;
	}

	return head;
}

ListNode* removeElements2(ListNode* head, int val) {
	if (head == NULL)
		return head;

	ListNode *l = head;

	while (l->next) {
		if (l->next->val == val)
			l->next = l->next->next;
		else
			l = l->next;
	}

	if (head->val == val)
		head = head->next;

	return head;
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

    cout << "\n Enter the value you want to delete: ";
    cin >> target;

	l1 = removeElements(head1, target);

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
