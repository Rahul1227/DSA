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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        // line ==> level ==> multiset
        map<int, map<int,vector<int>>> mp;
        //node, line, level
        queue<tuple<TreeNode*, int , int>> q;
        q.push({root,0,0});
        while(!q.empty()){
            auto [node, line, level] = q.front();
            q.pop();
            mp[line][level].push_back(node->val);
            if(node->left){
                q.push({node->left,line-1, level +1});
            }
            if(node->right){
                q.push({node->right, line+1, level +1});
            }
        }


        for(auto [key, val] : mp){
            vector<int> temp;
            for(auto [key2, val2] :val){
                sort(val2.begin(), val2.end());
                for(auto num : val2){
                    temp.push_back(num);
                }
            }

            ans.push_back(temp);
        }

        return ans;
        
    }
};