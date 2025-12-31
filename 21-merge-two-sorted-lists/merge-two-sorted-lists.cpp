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
    ListNode * solve(ListNode * l1, ListNode * l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode * result;
        if(l1->val <= l2->val){
            result = l1;
            l1->next = solve(l1->next, l2);
        }else{
            result = l2;
            l2 ->next = solve(l1, l2->next);
        }

        return result;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return solve(list1, list2);
        
    }
};