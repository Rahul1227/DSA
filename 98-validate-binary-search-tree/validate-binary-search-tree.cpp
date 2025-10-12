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
    void getInorder(TreeNode * root, vector<int> &inOrder){
        if(!root){
            return;
        }
        getInorder(root->left,inOrder);
        inOrder.push_back(root->val);
        getInorder(root->right,inOrder);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        getInorder(root,inOrder);

        int n = inOrder.size();
        for(int i =1; i<n; i++){
            if(inOrder[i-1] >= inOrder[i]){
                return false;
            }
        }
        return true;
        
    }
};