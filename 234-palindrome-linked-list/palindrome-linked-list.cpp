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
    bool check(vector<int> &temp){
        int n = temp.size();
        int left = 0;
        int right = n-1;
        while(left < right){
            if(temp[left] != temp[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        // trying array approach
        vector<int> tempArr;
        ListNode * temp = head;
        while(temp){
            tempArr.push_back(temp->val);
            temp = temp->next;
        }

        return check(tempArr);

        
    }
};