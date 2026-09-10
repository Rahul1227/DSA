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
    // unordered_map<int,int> mp;
    pair<int,int> solve(TreeNode* root, int &count){
        if(!root) return {0,0};

        auto[leftSum, leftNode] = solve(root->left, count);
        auto[rightSum, rightNode] = solve(root->right, count);

        int currSum = leftSum + rightSum + root->val;
        int currCount = 1 + leftNode + rightNode;

        int avg = currSum/currCount;
        if(root->val == avg){
            count++;
        }

        return {currSum, currCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        solve(root, count);
        return count;        
    }
};