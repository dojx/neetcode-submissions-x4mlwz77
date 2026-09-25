class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        unordered_map<TreeNode*, int> depth;
        stack<TreeNode*> stk;
        stack<TreeNode*> postOrder; // to reverse into post-order

        // Step 1: get a post-order sequence (children before parent)
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            postOrder.push(node);
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }

        // Step 2: process nodes in post-order (children already computed)
        int res = 0;
        while (!postOrder.empty()) {
            TreeNode* node = postOrder.top(); postOrder.pop();
            int leftDepth = node->left ? depth[node->left] : 0;
            int rightDepth = node->right ? depth[node->right] : 0;

            res = max(res, leftDepth + rightDepth);
            depth[node] = max(leftDepth, rightDepth) + 1;
        }

        return res;
    }
};