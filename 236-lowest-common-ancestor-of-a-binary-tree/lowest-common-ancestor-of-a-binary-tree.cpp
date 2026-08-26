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
    int solve(TreeNode* root, TreeNode* p, TreeNode*q, TreeNode* &ans){
        if(!root){
            return 0;
        }

        int leftChild = solve(root->left,p,q,ans);
        int rightChild = solve(root->right, p,q,ans);

        int totalChild = leftChild + rightChild;

        if(root == p || root == q){
            totalChild++;
        }

        if(totalChild ==2 && ans == nullptr){
            ans = root;
        }

        return totalChild;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        solve(root, p,q, ans);
        return ans;
        
    }
};