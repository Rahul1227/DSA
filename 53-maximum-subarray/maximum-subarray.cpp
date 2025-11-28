class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        int n = nums.size();
        int i =0;
        int j =0;
        while(j<n){
            currSum  += nums[j];
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
                i = j+1;
            }
            j++;
        }
        return maxSum;
        
    }
};