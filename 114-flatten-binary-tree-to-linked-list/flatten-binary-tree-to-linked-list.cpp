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
    TreeNode * solve(TreeNode * &root){
        if(!root) return NULL;
        TreeNode * leftTree = solve(root->left);
        TreeNode * rightTree = solve(root->right);
        root->left = NULL;
        if(leftTree){
            root->right = leftTree;
            TreeNode * temp = leftTree;
            while(temp -> right){
                temp = temp ->right;
            }
            temp -> right = rightTree;

        }else{
            root->right = rightTree;
        }

        return root;
    }
public:
    void flatten(TreeNode* root) {
        solve(root);
        
    }
};