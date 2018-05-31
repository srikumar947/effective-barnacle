/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

ListNode(int x) : val(x), next(NULL) {}
*/



#include <iostream>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    
    ListNode *head1, *head2, *head3, *l3;
    
    head1 = l1;
    head2 = l2;
    
    int sum, val, carry = 0, flag = 1;

    while (head1 && head2)
    {
        sum = head1->val + head2->val + carry;
        
        carry = 0;        
        
        if (sum > 9)
        {
            val = sum % 10;
            carry = 1;
        }
        else
            val = sum;

        head1 = head1->next;
        head2 = head2->next;

        ListNode* temp = new ListNode(val);
        
        if (flag == 1)
        {
            head3 = temp;
            l3 = temp;
            flag = 0;
        }

        else
        {
            l3->next = temp;
            l3 = temp;    
        }
    }

    while (head1)
    {
        sum = head1->val + carry;
        carry = 0;

        if (sum > 9)
        {
            val = sum % 10;
            carry = 1;
        }
        else
            val = sum;

        head1 = head1->next;

        ListNode* temp = new ListNode(val);
        l3->next = temp;
        l3 = temp;
    }
    
    while (head2)
    {
        sum = head2->val + carry;
        carry = 0;

        if (sum > 9)
        {
            val = sum % 10;
            carry = 1;
        }
        else
            val = sum;

        head2 = head2->next;

        ListNode* temp = new ListNode(val);
        l3->next = temp;
        l3 = temp;
    }

    if (carry == 1)
    {
        ListNode* temp = new ListNode(carry);
        l3->next = temp;
        l3 = temp;   
    }
    
    return head3;
}

int main()
{
	ListNode *l1, *l2, *l3, *head1, *head2;

	int number1, number2, flag = 1;

	cout << "\n Enter the two numbers: ";
	cin >> number1 >> number2;
	
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

	flag = 1;

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