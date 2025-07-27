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
    int getMaxdepth(TreeNode* node, int &maxDai){
        if(node == NULL){
            return 0;
        }

        int lt = getMaxdepth(node -> left, maxDai);
        int rt = getMaxdepth(node -> right, maxDai);
        maxDai = max(maxDai, lt+rt);
        return 1 + max(lt, rt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDai = 0;
        getMaxdepth(root, maxDai);
        return maxDai;
        
        

    }
};