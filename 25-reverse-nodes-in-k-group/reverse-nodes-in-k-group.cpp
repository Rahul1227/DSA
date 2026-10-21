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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int> st;
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        while(temp1){
            st.push(temp1->val);
            if(st.size() == k){
                while(!st.empty()){
                    temp2 -> val = st.top();
                    st.pop();
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }

        return head;
        
    }
};