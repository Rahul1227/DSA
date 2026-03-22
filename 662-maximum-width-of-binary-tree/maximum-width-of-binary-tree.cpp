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
        // if(!root) return 0;
        // left = 2 * i + 1
        // right = 2 * i + 2
        int ans = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int minInd = q.front().second;
            int maxInd = q.back().second;
            int curr = maxInd - minInd +1;
            ans = max(ans, curr);

            int n = q.size();
            for(int i =0; i<n; i++){
                auto [node, ind] = q.front();
                q.pop();
                int normalizedInd = ind - minInd;
                if(node->left){
                    q.push({node->left, (long long)2 * normalizedInd + 1});
                }

                if(node->right){
                    q.push({node->right, (long long)2 * normalizedInd + 2});
                }
            }
        }
        return ans;
        
    }
};