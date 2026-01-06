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
    void solve(TreeNode * root, int level, map<int,int> &mp){
        if(!root) return;

        mp[level] += root->val;
        solve(root->left, level+1, mp);
        solve(root->right, level+1, mp);
    }
public:
    int maxLevelSum(TreeNode* root) {
        map<int,int> mp;
        solve(root,1,mp);
        int maxSum = INT_MIN;
        int maxSumInd = -1;
        for(auto [key, val] : mp){
            if(val > maxSum){
                maxSum = val;
                maxSumInd = key;
            }
        }

        return maxSumInd;
        
    }
};