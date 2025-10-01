class Solution {
private:
    int solve(TreeNode * root){
        if(!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);

        return 1 + max(left, right);  // ✅ return height, not diff
    }

    void controller(TreeNode * root, int &diff){
        if(!root) return;

        int left = solve(root->left);
        int right = solve(root->right);

        diff = max(diff, abs(left - right)); // ✅ track the maximum difference

        // keep checking children
        controller(root->left, diff);
        controller(root->right, diff);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        int diff = 0;
        controller(root, diff);
        return diff <= 1;  // ✅ check final max difference
    }
};
