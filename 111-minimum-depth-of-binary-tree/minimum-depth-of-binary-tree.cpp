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
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root -> left == NULL && root-> right == NULL) return 1;

        int lt = root -> left ? minDepth(root -> left) : INT_MAX;
        int rt = root->right ? minDepth(root->right) : INT_MAX;
        return 1 + min(lt, rt);

        // if(root == NULL) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // int level = 1;
        // while(!q.empty()){
        //     int n = q.size();
        //     while (n--){
        //         TreeNode* temp = q.front();
        //         q.pop();

        //         if(temp -> left == NULL && temp->right == NULL){
        //             return level;
        //         } 

        //         if(temp -> left) q.push(temp->left);
        //         if(temp -> right) q.push(temp->right);
        //     }
        //     level++;
        // }
        // return -1;
    }
};