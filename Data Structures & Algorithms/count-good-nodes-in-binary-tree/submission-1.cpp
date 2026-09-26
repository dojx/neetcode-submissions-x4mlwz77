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
    int goodNodes(TreeNode* root) {
        /*
                    3
                3       null
            4      2 null   null
        */
        stack<pair<TreeNode*, int>> stk; // node, maxValueSeen
        stk.push({root, root->val});
        int res = 1;
        while (!stk.empty()) {
            auto p = stk.top(); stk.pop();
            TreeNode *tmp = p.first;
            int maxVal = p.second;
            if (tmp->left) {
                if (maxVal <= tmp->left->val) {
                    res++;
                    stk.push({tmp->left, tmp->left->val});
                } else {
                    stk.push({tmp->left, maxVal});
                }
            }
            if (tmp->right) {
                if (maxVal <= tmp->right->val) {
                    res++;
                    stk.push({tmp->right, tmp->right->val});
                } else {
                    stk.push({tmp->right, maxVal});
                }
            }
        }
        return res;
    }
};
