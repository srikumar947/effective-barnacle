/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

#include <iostream>
#include <vector>
#include <string>

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

void helper(TreeNode *root, vector<string>& ret, string path) {
    if (!root->left && !root->right)
        ret.push_back(path);

    else {
        if (root->left)
            helper(root->left, ret, path + "->" + to_string(root->left->val));
        if (root->right)
            helper(root->right, ret, path + "->" + to_string(root->right->val));
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;

    if (!root)
        return ret;

    helper(root, ret, to_string(root->val));
    return ret;
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

    vector<string> ret = binaryTreePaths(root);

    for (i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }

    cout << "\n\n";
    return 0;
}
