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
    TreeNode* solve(TreeNode* &root){
        if(!root) return NULL;
        
        TreeNode* leftHead = solve(root->left);
        TreeNode* rightHead = solve(root->right);

        root->left = NULL;
        if(leftHead){
            root->right = leftHead;
            TreeNode* temp = root;
            while(temp->right){
                temp = temp->right;
            }
            temp->right = rightHead;
            
        }else{
            root->right = rightHead;
        }

        return root;

        
    }
public:
    void flatten(TreeNode* root) {
        solve(root);
        
    }
};