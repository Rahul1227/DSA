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
    ListNode* solve(ListNode* l1, ListNode* l2){
        ListNode * head = new ListNode(-1);
        ListNode * temp = head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp -> next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp -> next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if(l1) temp -> next = l1;
        if(l2) temp ->next = l2;
        return head->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // trying the merge sort technique
        int n = lists.size();
        if(n == 0){
            return nullptr;
        }

        if(n==1){
            return lists[0];
        }
        ListNode * temp = lists[0];
        for (int i = 1; i < n; i++) {
            temp = solve(temp, lists[i]);
           
        }
        return temp;
    }
};