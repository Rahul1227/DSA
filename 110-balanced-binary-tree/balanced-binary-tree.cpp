class Solution {
private:
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = solve(root->left);
        if(left == -1) return -1;  // subtree unbalanced

        int right = solve(root->right);
        if(right == -1) return -1; // subtree unbalanced

        if(abs(left - right) > 1) return -1; // current node unbalanced

        return max(left, right) + 1; // return height
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};
