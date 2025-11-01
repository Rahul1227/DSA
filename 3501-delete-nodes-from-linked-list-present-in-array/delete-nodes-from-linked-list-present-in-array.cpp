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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        if(n == 0) return head;
        // creating a lookup for the elements to be searched
        map<int,int> mp;
        for(int i =0; i<n; i++){
            mp[nums[i]]=1;
        }

        // travering through the list
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            if(mp.find(curr->val) != mp.end()){
                if(curr == head){
                    head = curr->next;
                    curr= head;
                }else{
                    prev->next = curr->next;
                    curr = curr->next;
                }

            }else{
                prev = curr;
                curr = curr->next;
            }
            
        }

        return head;

        
        
    }
};