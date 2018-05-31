/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

Given the following binary search tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
Example 1:

Input: root, p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.
Example 2:

Input: root, p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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

bool find(TreeNode *root, vector<TreeNode*>& path, TreeNode *node) {
    if (!root)
        return false;

    path.push_back(root);

    if (root == node)
        return true;

    if ((root->left && find(root->left, path, node)) || (root->right && find(root->right, path, node)))
        return true;

    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q)
        return NULL;

    vector<TreeNode*> pt, qt;
    int i = 0, j = 0;

    if (find(root, pt, p) && find(root, qt, q)) {
        for(i = 0, j = 0; i < pt.size(), j < qt.size(); i++, j++) {
            if (pt[i] != qt[j])
                break;
        }
        return pt[i - 1];
    }

    else
        return NULL;
}

// Without extra space
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!p || !q)
        return NULL;

    if (!root || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor2(root->left, p, q);
    TreeNode *right = lowestCommonAncestor2(root->right, p, q);

    if (left && right)
        return root;

    if (left)
        return left;
    return right;
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

    if (root)
        root = lowestCommonAncestor2(root, root->left->left, root->left->right);
    else
        root = NULL;

    if (root)
        cout << "\n LCA: " << root->val;
    else
        cout << "\n No LCA";

    cout << "\n\n";
    return 0;
}
