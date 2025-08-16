/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, TreeNode* root, ListNode* temp){
        if(!temp) return true;

        if(temp && !root) return false;

        if(temp->val != root->val){
            return false;
        }
        bool left = solve(head, root->left, temp->next);
        bool right = solve(head, root->right, temp->next);
        return left || right;
    }

    bool solve1(ListNode *head, TreeNode* root){
        if(!root) return false;
        if(solve(head, root, head)) return true;
        bool left = solve1(head, root->left);
        bool right = solve1(head, root->right);
        return left || right;

    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head || !root) return false;
       
        return solve1(head, root);
    }
};