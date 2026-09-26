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
        queue<tuple<TreeNode*, int, int>> q;
        q.push(make_tuple(root, -INT_MAX, INT_MAX)); 
        while(!q.empty()) {
            auto [tmp, lower, upper] = q.front(); q.pop();
            if (tmp->val <= lower || tmp->val >= upper) return false;
            if (tmp->left) q.push(make_tuple(tmp->left, lower, tmp->val));
            if (tmp->right) q.push(make_tuple(tmp->right, tmp->val, upper));
        }
        return true;
    }
};
