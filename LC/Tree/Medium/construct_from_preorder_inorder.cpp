/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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

void inorderT(TreeNode *root) {
    if (root) {
        inorderT(root->left);
        cout << root->val << " ";
        inorderT(root->right);
    }
}

void preorderT(TreeNode *root) {
    if (root) {
        cout << root->val << " ";
        preorderT(root->left);
        preorderT(root->right);
    }
}

void postorderT(TreeNode *root) {
    if (root) {
        postorderT(root->left);
        postorderT(root->right);
        cout << root->val << " ";
    }
}

TreeNode* builder(vector<int>& preorder, int& index, vector<int>& inorder, int start, int end) {
    if (index >= preorder.size() || start > end)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index]);

    auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[index]));

    index += 1;

    if (pos >= 0 && pos < inorder.size()) {
        root->left = builder(preorder, index, inorder, start, pos - 1);
        root->right = builder(preorder, index, inorder, pos + 1, end);
    }

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    return builder(preorder, index, inorder, 0, inorder.size() - 1);
}

int main() {
    int i, n, x;
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    TreeNode *root = NULL;

    root = buildTree(preorder, inorder);

    cout << "\n Inorder Traversal: ";
    inorderT(root);

    cout << "\n\n Preorder Traversal: ";
    preorderT(root);

    cout << "\n\n Postorder Traversal: ";
    postorderT(root);

    cout << "\n\n";
    return 0;
}
