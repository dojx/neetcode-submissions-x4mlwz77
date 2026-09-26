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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        stack<TreeNode*> s1, s2;
        s1.push(p); s2.push(q);
        while (!s1.empty()) {
            TreeNode *tmp1 = s1.top(), *tmp2 = s2.top();
            s1.pop(); s2.pop();
            if (tmp1->val != tmp2->val) return false;
            if (tmp1->left && tmp2->left) {
                s1.push(tmp1->left); s2.push(tmp2->left);
            } else if (tmp1->left != tmp2->left) {
                return false;
            }
            if (tmp1->right && tmp2->right) {
                s1.push(tmp1->right); s2.push(tmp2->right);
            } else if (tmp1->right != tmp2->right) {
                return false;
            }
        }
        return s2.empty();
    }
};
