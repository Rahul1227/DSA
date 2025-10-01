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
    int solve(TreeNode* root, int &maxSum){
        if(!root){
            return 0;
        }

        int left = solve(root->left, maxSum);
        int right = solve(root->right, maxSum);

        int sum = left + right + root->val;
        if(sum > maxSum){
            maxSum = sum;
        }

        return max((max(left, right) + root->val),0);
        

    }


public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
        
    }
};