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
    TreeNode* getRightMost(TreeNode* node){
        TreeNode* ans = NULL;
        while(node->right){
            ans = node->right;
            node = node->right;
        }
        return ans;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode* newRoot = root->left;
                TreeNode* rightMost = getRightMost(root->left);
                if(rightMost){
                    rightMost ->right = root;
                }else{
                    newRoot->right = root;
                }

                root->left = NULL;
                root = newRoot;
                
            }else{
                ans.push_back(root->val);
                root = root->right;
            }
        }

        return ans;
        
    }
};