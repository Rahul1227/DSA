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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        vector<int> ans;

        q.push({root,0});
        while(!q.empty()){
            auto [node, level] = q.front();
            q.pop();
            mp[level] = node -> val;
            if(node -> left) q.push({node->left, level + 1});
            if(node -> right) q.push({node->right, level + 1});
        }

        for(auto [key, val]: mp){
            ans.push_back(val);
        }
        return ans;

        
        
    }
};