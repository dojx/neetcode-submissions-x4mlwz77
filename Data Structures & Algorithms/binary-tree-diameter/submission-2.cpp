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
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        int res = 0;
        while (!stk.empty()) {
            TreeNode *tmp = stk.top(); stk.pop();
            int diameter = maxDepth(tmp->left) + maxDepth(tmp->right);
            res = max(res, diameter);
            if (tmp->left) stk.push(tmp->left);
            if (tmp->right) stk.push(tmp->right);
        }
        return res;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});
        int res = 0;
        while (!stk.empty()) {
            auto p = stk.top(); stk.pop();
            TreeNode *tmp = p.first;
            int depth = p.second;
            res = max(res, depth);
            if (tmp->left) stk.push({tmp->left, depth + 1});
            if (tmp->right) stk.push({tmp->right, depth + 1});
        }
        return res;
    }
};
