/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        bool allowed1 = true;
        bool allowed2 = true;
        while(temp1 && temp2){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            if(!temp1 && allowed1){
                temp1 = headB;
                allowed1 = false;
            }

            temp2 = temp2->next;
            if(!temp2 && allowed2){
                temp2 = headA;
                allowed2 = false;
            }
        }

        return NULL;
        
    }
};