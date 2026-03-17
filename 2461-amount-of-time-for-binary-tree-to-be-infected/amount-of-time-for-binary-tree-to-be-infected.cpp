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
    int solve(TreeNode* root, int start, int &result){
        if(!root) return 0;

        int lh = solve(root->left, start, result);
        int rh = solve(root->right, start, result);

        if(root->val == start){
            result = max(lh, rh);
            return -1;
        }

        if(lh < 0 || rh < 0){
            result = max(result, abs(lh) + abs(rh));
            if(lh < 0){
                return lh -1;
            }else{
                return rh - 1;
            }

        }else{
            return max(lh, rh) + 1;
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int result = 0;
        solve(root, start, result);
        return result;
        
    }
};