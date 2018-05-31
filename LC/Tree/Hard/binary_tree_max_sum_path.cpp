/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(TreeNode* root, int x) {
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

int helper(TreeNode *root, int& maxVal) {
    if (!root)
        return 0;

    int l = max(0, helper(root->left, maxVal));
    int r = max(0, helper(root->right, maxVal));

    maxVal = max(maxVal, l + r + root->val);

    return root->val + max(l, r);
}

int maxPathSum(TreeNode* root) {
    int maxVal = INT_MIN;
    helper(root, maxVal);
    return maxVal != INT_MIN ? maxVal : 0;
}

int main() {
    int i, n, x;
    TreeNode *root = NULL;

    cout << "\n Enter the number of elements: ";
    cin >> n;

    cout << "\n Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        root = buildTree(root, x);
    }

    cout << "\n Maximum sum: " << maxPathSum(root);

    cout << "\n\n";
    return 0;
}
