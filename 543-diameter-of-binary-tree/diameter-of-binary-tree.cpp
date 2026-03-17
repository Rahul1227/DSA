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
    int solve(TreeNode* node, int &diameter){
        if(!node) return 0;
        int lh = solve(node->left, diameter);
        int rh = solve(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter;

        
    }
};