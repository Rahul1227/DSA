/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode * node, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(!node){
            return 0;
        }
        int count = 0;
        if(node == p || node == q){
            count++;
        }
    
        count += solve(node->left, p,q,ans);
        count += solve(node->right, p,q,ans);

        if(count == 2 && ans == nullptr){
            ans = node;
        }

        return count;
    }
        
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        solve(root, p,q, ans);
        return ans;
        
    }
};