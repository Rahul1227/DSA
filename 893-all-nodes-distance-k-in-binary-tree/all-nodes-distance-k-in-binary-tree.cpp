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
    void getParents(TreeNode* node, unordered_map<TreeNode*, TreeNode*> & parents){
        if(!node) return;

        if(node->left){
            parents[node->left] = node;
        }
        if(node->right){
            parents[node->right] = node;
        }
        getParents(node->left, parents);
        getParents(node->right, parents);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] =  NULL;
        getParents(root, parents);\
        unordered_map<TreeNode*, bool> visited;
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        while(!q.empty() && k--){
            int len = q.size();
            for(int i =0; i< len; i++){
                auto node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                TreeNode * parent = parents[node];
                if(parent!= NULL && !visited[parent]){
                    q.push(parent);
                    visited[parent] = true;
                }
            }
        }

        if(q.empty()) return {};
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};