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
    TreeNode* solve(int inStart, int inEnd, int postStart, int postEnd, 
    unordered_map<int,int>& inorder, vector<int> &postOrder){
        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }

        int rootVal = postOrder[postEnd];
        int i = inorder[rootVal];
        int leftCount = i - inStart;
        int rightCount = inEnd - i;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(inStart, i-1, postStart, postStart + leftCount-1, inorder, postOrder);
        root->right = solve(i+1, inEnd, postEnd - rightCount, postEnd -1, inorder, postOrder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i =0; i<n; i++){
            mp[inorder[i]] = i;
        }

        return solve(0,n-1, 0, n-1, mp, postorder);
        
    }
};