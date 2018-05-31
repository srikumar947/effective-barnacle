/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Your BSTIterator will be called like this:

BSTIterator i = BSTIterator(root);

while (i.hasNext())
    cout << i.next();

*/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode *root) {
        while(root) {
            myStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *t = myStack.top();
        myStack.pop();

        int ret = t->val;
        t = t->right;
        
        while (t) {
            myStack.push(t);
            t = t->left;
        }
        
        return ret;
    }
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

    BSTIterator it(root);

    while (it.hasNext())
        cout << it.next() << " ";

    cout << "\n\n";
    return 0;
}
