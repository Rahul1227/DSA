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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0LL});
        while(!q.empty()){
            int n = q.size();
            long long normaliza = q.front().second;
            int currWidth = q.back().second - q.front().second + 1;
            ans = max(ans, currWidth);
            for(int i =0; i<n; i++){
                auto [node , idx] = q.front();
                q.pop();
                int ind = idx - normaliza;
                if(node->left){
                    q.push({node->left, (long long)2 * ind + 1});
                }

                if(node ->right){
                    q.push({node->right,(long long)2 * ind + 2});
                }

            }
        }

        return ans;

        
    }
};