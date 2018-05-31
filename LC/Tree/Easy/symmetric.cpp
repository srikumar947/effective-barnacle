/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

#include <iostream>
#include <vector>

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

bool isMirror(TreeNode *p, TreeNode *q) {
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left))
        return true;

    return false;
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
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
    
    cout << "\n The tree is symmetric: " << isSymmetric(root);

    cout << "\n\n";
    return 0;
}
