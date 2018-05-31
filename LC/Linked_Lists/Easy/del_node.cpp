/*

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Suppose the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Replace value of node with next node's value until final node
void deleteNode(ListNode* node) {
	while (node->next) {
		node->val = node->next->val;

		if (node->next->next == NULL) {
			node->next = NULL;
			break;
		}

		node = node->next;
	}
}

// Replace value of node with next node's value and move link to node->next->next
void deleteNode2(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}

int main() {
	ListNode *head = NULL, *l = NULL;
	int flag = 1, n, x, i;

	cout << "\n Enter number of elements: ";
	cin >> n;

	cout << "\n Enter elements: ";

	for (i = 0; i < n; i++) {
		cin >> x;
		ListNode *temp = new ListNode(x);
		if (flag == 1) {
			head = temp;
			l = head;
			flag = 0;
		}
		else {
			l->next = temp;
			l = temp;
		}
	}

	l = head;

	cout << "\n Enter node number you want to delete (except the last node): ";
	cin >> x;

	if (x > 0 && x < n) {
		for (i = 0; i < x - 1; i++)
			l = l->next;
		deleteNode2(l);
	}

	l = head;
	cout << "\n The list is: ";
	while (l) {
		cout << l->val << " ";
		l = l->next;
	}

	cout << "\n\n";
	return 0;
}
