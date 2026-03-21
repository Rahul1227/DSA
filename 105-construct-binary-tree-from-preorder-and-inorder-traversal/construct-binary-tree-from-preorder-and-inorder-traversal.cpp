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
    TreeNode* solve(vector<int>& preorder,  unordered_map<int,int> &inorder, int start, int end, int &idx){
        if(start > end) return NULL;

        int rootVal = preorder[idx];
        int i = inorder[rootVal];
        idx++;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, i-1, idx);
        root->right = solve(preorder, inorder, i+1, end, idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i =0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        return solve(preorder, mp, 0, n-1, idx);
        
    }
};