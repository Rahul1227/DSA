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
    int solve(TreeNode* root, int &totalSum){
        if(!root) return 0;

        int leftNeed = solve(root->left, totalSum);
        int rightNeed = solve(root->right, totalSum);

        totalSum += abs(leftNeed) + abs(rightNeed);

        return leftNeed + rightNeed + root->val -1;


    }
public:
    int distributeCoins(TreeNode* root) {
        int totalSum = 0;
        solve(root, totalSum);
        return totalSum;
        
    }
};