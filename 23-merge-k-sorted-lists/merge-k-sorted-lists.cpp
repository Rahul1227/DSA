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

using pii = pair<int, ListNode*>;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        for(auto list: lists){
            if(list){
                pq.push({list->val, list});
            }
            
        }

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(!pq.empty()){
            auto[val, l] = pq.top();
            pq.pop();
            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = newNode;
            l = l->next;
            if(l){
                pq.push({l->val, l});
            }
        }

        return ans->next;
        
    }
};