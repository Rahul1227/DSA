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
    void solve(TreeNode* root, int col, int row, map<int, map<int,vector<int>>> &mp){
        if(!root) return;

        mp[col][row].push_back(root->val);
        solve(root->left, col-1, row+1, mp);
        solve(root->right, col+1, row+1, mp);


    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        solve(root, 0,0, mp);

        vector<vector<int>> ans;

        for(auto& [key, val] : mp){
            vector<int> temp;
            for(auto &[key2, val2] : val){
                sort(val2.begin(), val2.end());
                for(auto num: val2){
                    temp.push_back(num);
                }
                
            }
            ans.push_back(temp);
        }

        return ans;
        
        
    }
};