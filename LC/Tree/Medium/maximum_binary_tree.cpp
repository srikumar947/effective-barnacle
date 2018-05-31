/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
Note:
The size of the given array will be in the range [1,1000].

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

int findMax(vector<int>& nums, int start, int end) {
    int pos = start;
    for (int i = start + 1; i <= end; i++)
        if (nums[pos] < nums[i])
            pos = i;
    return pos;
}

TreeNode* builder(vector<int>& nums, int start, int end) {
    if (start > end)
        return NULL;

    int pos = findMax(nums, start, end);

    TreeNode *root = new TreeNode(nums[pos]);

    root->left = builder(nums, start, pos - 1);
    root->right = builder(nums, pos + 1, end);

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int index = 0;
    return builder(nums, 0, nums.size() - 1);
}

int main() {
    int i, j;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *root = NULL;

    root = constructMaximumBinaryTree(nums);

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
