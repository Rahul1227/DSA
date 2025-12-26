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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode (-1);
        ListNode * temp = head;
        int n = lists.size();
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>> > minHeap;

        // pushing the head of all the linkedlist into the heap
        for(int i=0; i<n; i++){
            if(lists[i]){
                minHeap.push({lists[i]->val, lists[i]});
            }
            
    }

        // now working on the minHeap
        while(!minHeap.empty()){
            auto [val, node] = minHeap.top();
            minHeap.pop();
            temp -> next = node;
            temp = node;
            if(node->next){
                node = node ->next;
                minHeap.push({node->val, node});
            }
        }

        return head->next;

        
        
    }
};