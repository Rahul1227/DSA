class Solution {
private:
    TreeNode* solve(TreeNode* root){
        if(!root) return NULL;

        TreeNode *l = root->left;
        TreeNode *r = root->right;

        TreeNode *leftHead = solve(l);
        TreeNode *rightHead = solve(r);

        root->left = NULL;
        if(leftHead){
            root->right = leftHead;
            while(leftHead->right){
                leftHead = leftHead->right;
            }
            leftHead->right = rightHead;
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
