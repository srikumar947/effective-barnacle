/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?

*/

#include <iostream>
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

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

TreeNode *previous = new TreeNode(INT_MIN);
TreeNode *first = NULL, *second = NULL;

void helper(TreeNode *root) {
    if (!root)
        return;

    helper(root->left);

    if (first == NULL && previous->val >= root->val)
        first = previous;

    if (first != NULL && previous->val >= root->val)
        second = root;

    previous = root;

    helper(root->right);
}


void recoverTree(TreeNode* root) {
    if (root) {
        helper(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
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

    x = root->val;
    root->val = root->right->val;
    root->right->val = x;

    recoverTree(root);

    cout << "\n Tree: ";
    inorder(root);

    cout << "\n\n";
    return 0;
}
