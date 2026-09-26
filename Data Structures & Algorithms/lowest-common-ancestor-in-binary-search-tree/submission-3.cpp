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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *tmp = root;
        while (tmp != nullptr) {
            if (p->val > tmp->val && q->val > tmp->val) {
                tmp = tmp->right;
            } else if (p->val < tmp->val && q->val < tmp->val) {
                tmp = tmp->left;
            } else {
                return tmp;
            }
        }
        return tmp;
    }
};
