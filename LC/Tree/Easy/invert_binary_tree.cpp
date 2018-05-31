/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/

#include <iostream>

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

TreeNode* invertTree(TreeNode* root) {
    if (!root || !root->left && !root->right)
        return root;

    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = temp;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    return root;
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

    root = invertTree(root);

    cout << "\n After Inversion - ";

    cout << "\n\n Inorder Traversal: ";
    inorder(root);

    cout << "\n\n Preorder Traversal: ";
    preorder(root);

    cout << "\n\n Postorder Traversal: ";
    postorder(root);

    cout << "\n\n";
    return 0;
}
