/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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

void levelStore(TreeNode *root, vector<int>& vals, int height) {
    if (root) {
        if (height == 1)
            vals.push_back(root->val);
        else {
            levelStore(root->left, vals, height - 1);
            levelStore(root->right, vals, height - 1);
        }
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> store;

    if (root) {
        vector<int> vals;
        int height = maxDepth(root);
        
        for (int i = 1; i <= height; i++) {
            levelStore(root, vals, i);
            store.push_back(vals);
            vals.clear();
        }
    }

    return store;
}

int main() {
    int i, n, x, j;
    TreeNode *root = NULL;

    cout << "\n Enter the number of elements: ";
    cin >> n;

    cout << "\n Enter the elements: ";
    for (i = 0; i < n; i++) {
        cin >> x;
        root = buildTree(root, x);

    }
    
    vector<vector<int>> store = levelOrder(root);

    cout << "\n Level Order - \n";
    for (i = 0; i < store.size(); i++) {
        for (j = 0; j < store[i].size(); j++) {
            cout << store[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";
    return 0;
}
