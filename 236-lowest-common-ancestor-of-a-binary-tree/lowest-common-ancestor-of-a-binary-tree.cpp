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
    int solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(!root) return 0;

        int count = 0;

        if(root == p || root == q){
            count++;
        }

        count += solve(root->left, p,q,ans);
        count += solve(root->right, p,q,ans);


        if(count == 2 && ans == nullptr){
            ans = root;
        }

        return count;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        solve(root, p, q, ans);
        return ans;
        
    }
};