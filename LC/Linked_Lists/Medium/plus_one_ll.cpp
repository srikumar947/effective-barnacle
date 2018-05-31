/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode *head) {
    ListNode *current = head, *next = NULL, *previous = NULL;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

ListNode* plusOne(ListNode* head) {
    ListNode *newHead = NULL, *l = head;
    int carry = 0, sum, flag = 1;

    l = reverseList(l);

    while (l) {
        if (flag) {
            sum = l->val + 1;
            flag = 0;
        }
        else {
            sum = l->val + carry;
        }

        carry = 0;

        if (sum > 9) {
            carry = 1;
            sum = sum % 10;
        }

        ListNode *temp = new ListNode(sum);
        temp->next = newHead;
        newHead = temp;

        l = l->next;
    }

    if (carry) {
        ListNode *temp = new ListNode(carry);
        temp->next = newHead;
        newHead = temp;
    }

    return newHead;
}

int main() {
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

	l1 = plusOne(head1);

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
