class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int currSum = 0;
        for(int i =0; i<n; i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
        
    }
};