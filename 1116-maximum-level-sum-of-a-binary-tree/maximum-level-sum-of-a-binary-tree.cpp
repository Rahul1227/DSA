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
    int maxLevelSum(TreeNode* root) {
        int maxSum= INT_MIN;
        int maxSumInd = -1;
        queue<TreeNode*> q;
        q.push(root);
        int currInd = 0;
        while(!q.empty()){
            int currSum = 0;
            int len = q.size();
            currInd++;
            for(int i =0; i<len; i++){
                TreeNode * temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }

                currSum += temp->val;
            }

            if(currSum > maxSum){
                maxSum = currSum;
                maxSumInd = currInd;
            }
        }

        return maxSumInd;
        
    }
};