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
    int getHeight(TreeNode * root){
        if(!root) return 0;
        int leftHeight = 1 + getHeight(root->left);
        int rightHeight = 1 + getHeight(root->right);
        return max(leftHeight, rightHeight);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if(left == right) return root;
        if(left > right){
            return subtreeWithAllDeepest(root->left);
        }else{
            return subtreeWithAllDeepest(root->right);
        }
        
    }
};