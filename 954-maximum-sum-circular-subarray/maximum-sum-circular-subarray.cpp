class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currMax = 0;
        int currMin = 0;

        for(int i =0; i<nums.size();  i++){
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(currMin, minSum);
        }

        int cirSum = totalSum - minSum;

        if(maxSum < 0){
            return maxSum;
        }

        return max(cirSum, maxSum);
        
    }
};