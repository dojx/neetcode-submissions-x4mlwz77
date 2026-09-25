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
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int res = 0;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode *tmp = p.first;
            int depth = p.second;
            res = max(res, depth);
            if (tmp->left) q.push({tmp->left, depth + 1});
            if (tmp->right) q.push({tmp->right, depth + 1});
        }
        return res;
    }
};
