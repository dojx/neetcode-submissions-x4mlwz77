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

// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (root == nullptr) return true;
//         if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
//             return false;
//         return isBalanced(root->left) && isBalanced(root->right);
//     }

//     int maxDepth(TreeNode* root) {
//         if (root == nullptr) return 0;
//         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//     }
// };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> stk, postOrder;
        TreeNode *tmp;
        stk.push(root);
        while (!stk.empty()) {
            tmp = stk.top(); stk.pop();
            postOrder.push(tmp);
            if (tmp->left) stk.push(tmp->left);
            if (tmp->right) stk.push(tmp->right);
        }
        
        unordered_map<TreeNode*, int> depth;
        while (!postOrder.empty()) {
            tmp = postOrder.top(); postOrder.pop();
            int depthL, depthR;
            if (tmp->left) {
                depthL = depth[tmp->left];
            } else {
                depthL = 0;
            }
            if (tmp->right) {
                depthR = depth[tmp->right];
            } else {
                depthR = 0;
            }
            if (abs(depthL - depthR) > 1) return false;
            depth[tmp] = max(depthL, depthR) + 1;
        }

        return true;
    }
};