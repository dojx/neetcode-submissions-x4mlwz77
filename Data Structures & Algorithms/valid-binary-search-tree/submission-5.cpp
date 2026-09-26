/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, -INT_MAX, root->val) && helper(root->right, root->val, INT_MAX);
    }

    bool helper(TreeNode* root, int lower, int upper) {
        if (root == nullptr) return true;
        if (root->val >= upper || root->val <= lower) return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
};
