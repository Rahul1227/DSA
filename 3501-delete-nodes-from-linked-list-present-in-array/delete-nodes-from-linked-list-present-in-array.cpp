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

        // extracting the node values
        vector<int> tempStore;
        ListNode* temp = head;
        while(temp){
            int value = temp -> val;
            tempStore.push_back(value);
            temp = temp -> next;
        }

        vector<int> finalAns;
        for(auto num: tempStore){
            if(mp.find(num) == mp.end()){
                finalAns.push_back(num);
            }
        }

        ListNode * head1 = NULL;
        ListNode * temp1 = NULL;
        for(int i =0; i< finalAns.size(); i++){
            ListNode* newNode = new ListNode(finalAns[i]);
            if(head1 == NULL){
                head1 = newNode;
                temp1 = head1;
            }else{
                temp1 -> next = newNode;
                temp1 = newNode;
            }
        }
        return head1;
        
    }
};