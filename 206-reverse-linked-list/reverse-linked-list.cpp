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
class Solution {
private:
    ListNode *reverse(ListNode* &prev, ListNode* &curr){
        if(!curr) return prev;
        ListNode * next = curr->next;
        curr->next = prev;
        return reverse(curr,next);


    }
    
public:
    ListNode* reverseList(ListNode* head) {
        //trying the recursive solution
        ListNode * prev = nullptr;
        ListNode * curr = head;
        return reverse(prev, curr);
        






        //Iterative solution
        // ListNode * prev = nullptr;
        // ListNode * curr = head;
        // while(curr){
        //     ListNode * next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;
        
    }
};