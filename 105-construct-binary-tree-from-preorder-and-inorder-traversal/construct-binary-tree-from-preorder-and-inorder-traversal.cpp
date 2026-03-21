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
    TreeNode* solve(int inStart, int inEnd, int preStart, int preEnd, 
    unordered_map<int,int>& inorder, vector<int> &preOrder){
        if(inStart > inEnd || preStart > preEnd){
            return NULL;
        }

        int rootVal = preOrder[preStart];
        int i = inorder[rootVal];
        int leftCount = i - inStart;
        int rightCount = inEnd - i;
        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(inStart, i-1, preStart+1, preStart + leftCount, inorder, preOrder);
        root->right = solve(i+1, inEnd, preEnd - rightCount+1, preEnd, inorder, preOrder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i =0; i<n; i++){
            mp[inorder[i]] = i;
        }

        return solve(0,n-1, 0, n-1, mp, preorder);
        
    }
};