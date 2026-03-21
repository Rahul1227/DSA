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
private:
    int solve(TreeNode * root){
        if(!root) return 0;

        int lc = solve(root->left);
        int rc = solve(root->right);

        return lc + rc + 1;
    }
public:
    int countNodes(TreeNode* root) {
        return solve(root);
        
    }
};