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
        vector<int> ans;
        map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int currLevel = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto node = q.front();
                q.pop();
                int currVal = node->val;
                mp[currLevel] = currVal;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);


            }
            currLevel++;
        }

        for(auto &[key, val]: mp){
            ans.push_back(val);
        }

        return ans;
        
    }
};