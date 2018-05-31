/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome2(ListNode *head) {
	int i, j, n = 0;
	ListNode *l = head, *e = NULL;

	while (l) {
		n += 1;
		l = l->next;
	}

	l = head;

	for (i = 0; i < n/2; i++) {
		e = head;

		for (j = 0; j < n - i - 1; j++) {
			e = e->next;
		}

		if (l->val != e->val)
			return false;

		l = l->next;
	}

	return true;
}

bool isPalindrome(ListNode *head)
{
	if (head == NULL)
		return true;

	ListNode *l1 = head, *mid = NULL, *current = NULL, *next = NULL, *temp = NULL;
	int m = 0, flag = 1;
	float check, j;

	while (l1)
	{
		m += 1;

		if (flag == 1)
		{
			mid = l1;
			j = 1.0;
			flag = 0;
		}

		check = float(m) / 2.0;

		if (check > j)
		{
			mid = mid->next;
			j += 1.0;
		}

		l1 = l1->next;
	}

	current = mid->next;

	while (current)
	{
		next = current->next;
		current->next = temp;
		temp = current;
		current = next;
	}

	mid->next = temp;

	l1 = head;
	temp = mid->next;

	while (temp)
	{
		if (l1->val != temp->val)
			return false;
		l1 = l1->next;
		temp = temp->next;
	}

	return true;
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

    if (isPalindrome(head1) == 0)
		cout << "\n The list is not a palindrome.";
	else
		cout << "\n The list is a palindrome.";

	cout << endl;

	return 0;
}
