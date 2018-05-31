/*

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* tree)
{
	if (tree)
	{
		inorder(tree->left);
		cout << tree->val << " ";
		inorder(tree->right);
	}
}

TreeNode* buildTree(int *array, int start, int end)
{
	if (start <= end)
	{
		int mid = (end - start + 1) / 2;
		mid += start;
		TreeNode *root = new TreeNode(array[mid]);
		root->left = buildTree(array, start, mid - 1);
		root->right = buildTree(array, mid + 1, end);
		return root;
	}
	else
		return NULL;
}

TreeNode* sortedListToBST(ListNode* head)
{
	if (head == NULL)
		return NULL;

	ListNode *l = head;
	TreeNode *root = NULL;
	int len = 0, k = 0;

	while (l)
	{
		len += 1;
		l = l->next;
	}

	int *array = new int[len];

	l = head;

	while (l)
	{
		array[k++] = l->val;
		l = l->next;
	}

	root = buildTree(array, 0, len - 1);

	return root;
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

	TreeNode *t = sortedListToBST(head1);

	if (t)
	{
		cout << "\n\n The tree is: ";
		inorder(t);
	}
	
	else
		cout << "\n\n Empty tree.";
	
	cout << endl;

	return 0;
}