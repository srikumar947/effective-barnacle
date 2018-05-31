/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

   2
    \
     3
    /
   2
  /
 1

Output: 2

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
*/
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder (TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

TreeNode* buildTree (TreeNode *root, int x) {
    if (root == NULL) {
        TreeNode *temp = new TreeNode(x);
        root = temp;
    }
    else {
        if (root->val > x)
            root->left = buildTree(root->left, x);
        else
            root->right = buildTree(root->right, x);
    }
    return root;
}

int dfs(TreeNode *node, TreeNode *parent, int len) {
    if (!node)
        return len;

    if (parent && parent->val + 1 == node->val)
        len += 1;
    else
        len = 1;
    return max(len, max(dfs(node->left, node, len), dfs(node->right, node, len)));
}

int longestConsecutive(TreeNode* root) {
    return dfs(root, NULL, 0);
}

int main () {
    int i, n, *x;
    TreeNode *root = NULL;

    cout << "\n Enter number of elements: ";
    cin >> n;

    x = new int[n];

    cout << "\n Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> x[i];

    for (i = 0; i < n; i++)
        root = buildTree(root, x[i]);

    cout << "\n Longest sequence: " << longestConsecutive(root);

    cout << "\n\n";
}
