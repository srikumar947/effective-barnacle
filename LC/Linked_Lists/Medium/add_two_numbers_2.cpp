/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/


#include <iostream>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2)
{
    ListNode *l1 = NULL, *l2 = NULL, *head3 = NULL, *l3 = NULL, *current = NULL, *next = NULL, *temp1 = NULL;
    int n = 0, m = 0, carry = 0, i = 1, sum = 0, flag = 1;

    while (head1 && head1->val == 0)
    	head1 = head1->next;

    while (head2 &&head2->val == 0)
    	head2 = head2->next;

    if (head1 == NULL && head2 == NULL)
    {
    	ListNode *temp = new ListNode(0);
    	return temp;
    }

    else if (head1 == NULL)
    	return head2;

    else if (head2 == NULL)
    	return head1;

    else
    {
    	for (l1 = head1; l1; l1 = l1->next)
    	   n += 1;

	    for (l2 = head2; l2; l2 = l2->next)
	    	m += 1;

	    while (n && m)
	    {
	    	i = 1;
	    	l1 = head1;

	    	while (i < n)
	    	{
	    		l1 = l1->next;
	    		i += 1;
	    	}

	    	i = 1;
	    	l2 = head2;

	    	while (i < m)
	    	{
	    		l2 = l2->next;
	    		i += 1;
	    	}

	    	n -= 1;
	    	m -= 1;

	    	sum = l1->val + l2->val + carry;
	    	carry = 0;

	    	if (sum > 9)
	    	{
	    		sum = sum % 10;
	    		carry = 1;
	    	}

	    	ListNode *temp = new ListNode(sum);

	    	if (flag == 1)
	    	{
	    		head3 = temp;
	    		l3 = temp;
	    		flag = 0;
	    	}

	    	else
	    	{
	    		l3->next = temp;
	    		l3 = l3->next;
	    	}

	    }

	    while (n >= 1)
	    {
	    	i = 1;
	    	l1 = head1;

	    	while (i < n)
	    	{
	    		l1 = l1->next;
	    		i += 1;
	    	}

	    	n -= 1;

	    	sum = l1->val + carry;
	    	carry = 0;

	    	if (sum > 9)
	    	{
	    		sum = sum % 10;
	    		carry = 1;
	    	}

	    	ListNode *temp = new ListNode(sum);

	    	if (flag == 1)
	    	{
	    		head3 = temp;
	    		l3 = temp;
	    		flag = 0;
	    	}

	    	else
	    	{
	    		l3->next = temp;
	    		l3 = l3->next;
	    	}
	    }

	    while (m >= 1)
	    {
	    	i = 1;
	    	l2 = head2;

	    	while (i < m)
	    	{
	    		l2 = l2->next;
	    		i += 1;
	    	}

	    	m -= 1;

	    	sum = l2->val + carry;
	    	carry = 0;

	    	if (sum > 9)
	    	{
	    		sum = sum % 10;
	    		carry = 1;
	    	}

	    	ListNode *temp = new ListNode(sum);

	    	if (flag == 1)
	    	{
	    		head3 = temp;
	    		l3 = temp;
	    		flag = 0;
	    	}

	    	else
	    	{
	    		l3->next = temp;
	    		l3 = l3->next;
	    	}
	    }

	    if (carry == 1)
	    {
	    	ListNode *temp = new ListNode(1);
			l3->next = temp;
			l3 = l3->next;
			carry = 0;
	    }

	    current = head3;

	    while(current)
	    {
	    	next = current->next;
	    	current->next = temp1;
	    	temp1 = current;
	    	current = next;
	    }

	    head3 = temp1;

	    return head3;
    }
}

ListNode* addTwoNumbers2(ListNode* head1, ListNode* head2) {
    int num1 = 0, num2 = 0, flag = 0;
    ListNode *l1 = head1, *l2 = head2, *l3 = NULL;

    while (l1) {
        num1 = (num1 * 10) + l1->val;
        l1 = l1->next;
    }

    while (l2) {
        num2 = (num2 * 10) + l2->val;
        l2 = l2->next;
    }

    num1 += num2;

    while (num1) {
        ListNode *temp = new ListNode(num1 % 10);
        temp->next = l1;
        l1 = temp;
        num1 /= 10;
    }
    return l1;
}

int main()
{
	ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL, *head1 = NULL, *head2 = NULL, *current = NULL, *temp1 = NULL, *next = NULL;

	int number1, number2, flag = 1;

	cout << "\n Enter the two numbers: ";
	cin >> number1 >> number2;

	if (number1 == 0)
	{
		ListNode *temp = new ListNode(0);
		head1 = temp;
	}

	else
	{
		while (number1)
	    {
	        ListNode* temp = new ListNode(number1 % 10);

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

	        number1 /= 10;
	    }
	}


	flag = 1;

	if (number2 == 0)
	{
		ListNode *temp = new ListNode(0);
		head2 = temp;
	}

	else
	{
		while (number2)
	    {
	        ListNode* temp = new ListNode(number2 % 10);

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

	        number2 /= 10;
	    }
	}


    current = head1;

    while (current)
    {
    	next = current->next;
    	current->next = temp1;
    	temp1 = current;
    	current = next;
    }

    head1 = temp1;

    current = head2;
    temp1 = NULL;

    while (current)
    {
    	next = current->next;
    	current->next = temp1;
    	temp1 = current;
    	current = next;
    }

    head2 = temp1;

	l3 = addTwoNumbers(head1, head2);

	cout << "\n The addition is: ";

	while (l3)
	{
		if (l3->next != NULL)
			cout << l3->val << "->";
		else
			cout << l3->val;

		l3 = l3->next;
	}

	cout << endl;

	return 0;
}
