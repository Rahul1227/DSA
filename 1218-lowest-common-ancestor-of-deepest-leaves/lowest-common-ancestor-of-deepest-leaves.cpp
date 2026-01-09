/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, int> mp;

private:
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = 1 + getHeight(root->left);
        int rightHeight = 1 + getHeight(root->right);
        return mp[root] = max(leftHeight, rightHeight);
    }

    TreeNode* solve(TreeNode* root) {
        int left = mp[root->left];
        int right = mp[root->right];
        if (left == right)
            return root;
        if (left > right) {
            return solve(root->left);
        } else {
            return solve(root->right);
        }
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        getHeight(root);
        return solve(root);
    }
};