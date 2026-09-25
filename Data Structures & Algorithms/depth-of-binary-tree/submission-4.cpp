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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});
        int res = 0;
        while (!stk.empty()) {
            auto s = stk.top(); stk.pop();
            TreeNode* tmp = s.first;
            int depth = s.second;
            res = max(res, depth);
            if (tmp->left)
                stk.push({tmp->left, depth + 1});
            if (tmp->right)
                stk.push({tmp->right, depth + 1});
        }
        return res;
    }
};
