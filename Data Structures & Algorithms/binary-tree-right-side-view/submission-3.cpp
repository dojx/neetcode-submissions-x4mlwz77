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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool found = false;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *tmp = q.front(); q.pop();
                if (tmp) {
                    if (!found) {
                        found = true;
                        res.push_back(tmp->val);
                    }
                    q.push(tmp->right);
                    q.push(tmp->left);
                }
            }
        }
        return res;
    }
};
