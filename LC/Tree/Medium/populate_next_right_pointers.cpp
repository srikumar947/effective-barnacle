/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* buildTree(TreeLinkNode* root, int x) {
    if (root == NULL) {
        TreeLinkNode *temp = new TreeLinkNode(x);
        root = temp;
    }

    else if (root->val > x)
        root->left = buildTree(root->left, x);

    else
        root->right = buildTree(root->right, x);

    return root;
}

void print(TreeLinkNode *root) {
    cout << "\n";
    if (root) {
        TreeLinkNode *temp = root;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        print(root->left);
    }
}

// Recursive approach
void connect(TreeLinkNode *root) {
    if (!root)
        return;

    if (root->left) {
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL;
    }

    connect(root->left);
    connect(root->right);
}

// Iterative approach
void connect2(TreeLinkNode *root) {
    if (!root)
        return;

    while (root->left) {
        TreeLinkNode *temp = root;

        while (temp) {
            temp->left->next = temp->right;

            if (temp->next)
                temp->right->next = temp->next->left;

            temp = temp->next;
        }

        root = root->left;
    }
}

int main() {
    int i, n, x, j;
    TreeLinkNode *root = NULL;

    cout << "\n Enter the number of elements: ";
    cin >> n;

    cout << "\n Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        root = buildTree(root, x);

    }
    
    connect(root);
    
    print(root);

    cout << "\n\n";
    return 0;
}
