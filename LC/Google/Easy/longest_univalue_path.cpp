/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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

int dfs (TreeNode *node, int &ret) {
    int lheight = node->left ? dfs(node->left, ret) : 0;
    int rheight = node->right ? dfs(node->right, ret) : 0;
    int lresult = node->left && node->left->val == node->val ? lheight + 1 : 0;
    int rresult = node->right && node->right->val == node->val ? rheight + 1 : 0;
    ret = max(ret, lresult + rresult);
    return max(lresult, rresult);
}

int longestUnivaluePath (TreeNode* root) {
    int ret = 0;
    if (root)
        dfs(root, ret);
    return ret;
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

    cout << "\n Longest Univalue Path: " << longestUnivaluePath(root);

    cout << "\n\n";
}
