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
    int getSum(TreeNode * node, vector<int> &precomputed){
        if(!node) return 0;

        int leftSum = getSum(node->left, precomputed);
        int rightSum = getSum(node->right, precomputed);

        precomputed.push_back(leftSum +  rightSum + node->val);
        return precomputed.back();
    }
public:
    const int MOD = 1e9+7;
    int maxProduct(TreeNode* root) {
        vector<int> precomputed;
        int totalSum = getSum(root, precomputed);
        long long maxSum = 1;
        for(auto val : precomputed){
            long long sum1 = val;
            long long sum2 = totalSum - val;
            long long currSum = sum1 * sum2;
            maxSum = max(maxSum, currSum);

        }

        return maxSum % MOD;
        
        
    }
};