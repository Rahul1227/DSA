/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, TreeNode*& ans, TreeNode* p, TreeNode* q) {
        if (!root || ans != nullptr)
            return 0;

        int leftCount = solve(root->left, ans, p, q);
        int rightCount = solve(root->right, ans, p, q);

        int totalCount = leftCount + rightCount;

        if (root == p || root == q) {
            totalCount++;
        }

        if (ans == nullptr && totalCount == 2) {
            ans = root;
        }

        return totalCount;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        solve(root, ans, p, q);
        return ans;
    }
};