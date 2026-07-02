class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int totalSum =0;
        int currSumMax =0;
        int currSumMin =0;

        for(auto num : nums){
            // maxSum
            currSumMax = max(currSumMax + num, num);
            maxSum = max(maxSum, currSumMax);

            // minSum
            currSumMin = min(currSumMin + num, num);
            minSum = min(minSum, currSumMin);

            // totalSum 
            totalSum += num;
        }

        int cirMaxSum =  totalSum - minSum;
        if(maxSum > 0){
            return max(maxSum, cirMaxSum);
        }else{
            return maxSum;
        }
        
    }
};