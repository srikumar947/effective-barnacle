/*
Implement the following in a Binary Search Tree -
1. Insert an element (build a tree)
2. Find a node. If it doesn't exist, return NULL.
3. Find the lowest value in the tree.
4. Find the largest value in the tree.
5. Find the successor to a given node. Return NULL if doesn't exist.
6. Find the predecessor to a given node. Return NULL if doesn't exist.
7. Delete a given node.
8. Print the tree in in order, pre order, post order and level order.
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
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

TreeNode* buildTree(TreeNode* root, int x, TreeNode *parent) {
    if (root == NULL) {
        TreeNode *temp = new TreeNode(x);
        root = temp;
        root->parent = parent;
    }

    else if (root->val > x)
        root->left = buildTree(root->left, x, root);

    else
        root->right = buildTree(root->right, x, root);

    return root;
}

TreeNode* find(TreeNode *root, int x) {
    if (root) {
        if (root->val == x)
            return root;
        else if (root->val > x)
            return find(root->left, x);
        else
            return find(root->right, x);
    }
    return NULL;
}

TreeNode* treeMinimum(TreeNode *root) {
    while (root->left)
        root = root->left;
    return root;
}

TreeNode* treeMaximum(TreeNode *root) {
    while (root->right)
        root = root->right;
    return root;
}

TreeNode* successor(TreeNode *node) {
    if (node) {
        if (node->right)
            return treeMinimum(node->right);
        TreeNode *y = node->parent;
        while (y != NULL && y->right == node) {
            node = y;
            y = y->parent;
        }
        return y;
    }
    return NULL;
}

TreeNode* predecessor(TreeNode *node) {
    if (node) {
        if (node->left)
            return treeMaximum(node->left);
        TreeNode *y = node->parent;
        while (y != NULL && y->left == node) {
            node = y;
            y = y->parent;
        }
        return y;
    }
    return NULL;
}

TreeNode* transplant(TreeNode *root, TreeNode *a, TreeNode *b) {
    if (a->parent == NULL)
        root = b;
    else if (a->parent->left == a)
        a->parent->left = b;
    else
        a->parent->right = b;
    if (b)
        b->parent = a->parent;
    return root;
}

TreeNode* removeNode(TreeNode *root, TreeNode *node) {
    if (node) {
        if (!node->left)
            root = transplant(root, node, node->right);
        else if (!node->right)
            root = transplant(root, node, node->left);
        else {
            TreeNode *y = treeMinimum(node->right);
            if (y->parent != node) {
                root = transplant(root, y, y->right);
                y->right = node->right;
                y->right->parent = y;
            }
            root = transplant(root, node, y);
            y->left = node->left;
            y->left->parent = y;
        }
    }
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
        root = buildTree(root, x, NULL);
    }

    cout << "\n\n Inorder Traversal: ";
    inorder(root);

    cout << "\n\n Preorder Traversal: ";
    preorder(root);

    cout << "\n\n Postorder Traversal: ";
    postorder(root);

    cout << "\n\n Enter node to delete: ";
    cin >> x;

    TreeNode *y = find(root, x);
    root = removeNode(root, y);

    cout << "\n\n Inorder Traversal: ";
    inorder(root);

    cout << "\n\n Preorder Traversal: ";
    preorder(root);

    cout << "\n\n Postorder Traversal: ";
    postorder(root);

    cout << "\n\n";
    return 0;
}
