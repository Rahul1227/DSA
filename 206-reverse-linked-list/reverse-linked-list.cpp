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
    ListNode* solve(ListNode* currNode, ListNode* prevNode){
        if(currNode == nullptr){
            return prevNode;
        }
        ListNode* nextNode = currNode->next;
        currNode->next = prevNode;
        return solve(nextNode, currNode);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return solve(head, nullptr);
        
    }
};