class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
            approach
            1) create a n+1 size array
            2) mark all the elements present
            3) re-iterate and return all the missing ones
        */
        int n = nums.size();
        vector<int> presentElements(n+1, 0);
        vector<int> answer;
        for(int i=0; i<n; i++){
            presentElements[nums[i]] = 1;
        }

        for(int i=1; i<=n; i++){
            if(presentElements[i] == 0){
               answer.push_back(i); 
            }
        }
        return answer;
    }
};