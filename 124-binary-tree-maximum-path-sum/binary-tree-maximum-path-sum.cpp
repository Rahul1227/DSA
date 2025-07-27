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
    int calculateMaxSum (TreeNode* root, int &maxSum){
        if(root == NULL) return 0;

        int lt = max(0, calculateMaxSum(root->left,maxSum)); 
        int rt = max(0,calculateMaxSum(root->right, maxSum));

        maxSum = max(maxSum, lt + rt  + root->val);

        return root->val + max(lt, rt);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateMaxSum (root, maxSum);
        return maxSum;
        
    }
};