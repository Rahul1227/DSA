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
        if(!root) return 0;
        int leftSum = solve(root->left, maxSum);
        int rightSum = solve(root->right, maxSum);
        // cases
        int maxChildSum = max({leftSum, rightSum, leftSum + rightSum});
        int maxTillNow = max({maxChildSum+ root->val, root->val});
        maxSum = max(maxSum, maxTillNow);
        int maxofChild = max({leftSum, rightSum, 0});
        return max(root->val + maxofChild, root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
        
    }
};