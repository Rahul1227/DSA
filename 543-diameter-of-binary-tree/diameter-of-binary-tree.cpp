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
    int solve(TreeNode* root, int &maxDai){
        if(!root){
            return 0;
        }

        int left = solve(root->left, maxDai);
        int right = solve(root->right, maxDai);
        int currTotal = left + right;
        if(currTotal > maxDai){
            maxDai = currTotal;
        }
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDai = 0;
        solve(root, maxDai);
        return maxDai;
        
    }
};