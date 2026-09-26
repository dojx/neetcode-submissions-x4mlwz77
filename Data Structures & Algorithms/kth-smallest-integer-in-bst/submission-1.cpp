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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode *tmp = root;
        while (!tmp || !stk.empty()) {
            while (tmp) {
                stk.push(tmp);
                tmp = tmp->left;
            }

            tmp = stk.top(); stk.pop();
            k--;
            if (k == 0) return tmp->val;
            tmp = tmp->right;
        }
    }
};
