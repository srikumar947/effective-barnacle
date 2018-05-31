/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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

TreeNode* convert(vector<int> nums, int start, int end) {
	if (start <= end) {
		int mid = (start + end + 1) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = convert(nums, start, mid - 1);
		root->right = convert(nums, mid + 1, end);
		return root;
	}
	else
		return NULL;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return convert(nums, 0, nums.size() - 1);
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
		nums.push_back(x);
	}

	sort(nums.begin(), nums.end());

	root = sortedArrayToBST(nums);

	cout << "\n\n Inorder Traversal: ";
	inorder(root);

	cout << "\n\n Preorder Traversal: ";
	preorder(root);

	cout << "\n\n Postorder Traversal: ";
	postorder(root);

	cout << "\n\n";
	return 0;
}