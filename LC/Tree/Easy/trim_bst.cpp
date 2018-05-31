/*
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). 
You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2

  L = 1
  R = 2

Output: 
    1
      \
       2
Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output: 
      3
     / 
   2   
  /
 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode *root) {
	if (root) {
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
}

void preorder(TreeNode *root) {
	if (root) {
		cout << root->val << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->val << " ";
	}
}

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);

    if (lheight > rheight)
        return lheight + 1;
    return rheight + 1;
}

TreeNode* buildTree(TreeNode *root, int x) {
	if (root == NULL) {
		TreeNode *temp = new TreeNode(x);
		root = temp;
	}

	else if (root->val > x)
		root->left = buildTree(root->left, x);

	else
		root->right = buildTree(root->right, x);

	return root;
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
	if (!root)
		return NULL;

	if (root->val < L)
		return trimBST(root->right, L, R);

	else if (root->val > R)
		return trimBST(root->left, L, R);

	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);

	return root;
}

int main() {
	TreeNode *root = NULL;
	int n, i, x;
	vector<int> nums;

	cout << "\n Enter number of elements: ";
	cin >> n;

	cout << "\n Enter the elements: ";
	
	for (i = 0; i < n; i++) {
		cin >> x;
		root = buildTree(root, x);
	}

	cout << "\n Enter (L, R): ";
	cin >> i >> n;

	root = trimBST(root, i, n);	

	cout << "\n\n Inorder Traversal: ";
	inorder(root);

	cout << "\n\n Preorder Traversal: ";
	preorder(root);

	cout << "\n\n Postorder Traversal: ";
	postorder(root);

	cout << "\n\n";
	return 0;
}