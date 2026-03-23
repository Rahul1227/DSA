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
    int solve(TreeNode* node, int &ans){
        if(!node) return 0;

        int leftVal = solve(node->left, ans);
        int rightVal = solve(node->right, ans);

        int firstCase = leftVal + rightVal + node->val;
        int secondCase = max(leftVal, rightVal) + node->val;
        int thirdCase = node->val;
        ans = max({ans, firstCase, secondCase, thirdCase});

        return max(secondCase, thirdCase);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};