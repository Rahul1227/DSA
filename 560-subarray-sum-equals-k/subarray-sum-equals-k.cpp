class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force approach
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            int currSum = 0;
            for(int j = i; j<nums.size(); j++){
                currSum += nums[j];
                if(currSum == k){
                    result++;
                }

            }
        }
        return result;
        
    }
};