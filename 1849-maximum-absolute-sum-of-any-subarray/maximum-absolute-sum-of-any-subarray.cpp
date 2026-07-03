class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currSumMax = 0;
        int currSumMin = 0;

        for(auto num : nums){
            // maxSUm
            currSumMax = max(num, currSumMax + num);
            maxSum = max(maxSum, currSumMax);

            // minSum
            currSumMin = min(num, currSumMin + num);
            minSum = min(minSum, currSumMin);
        }

        return max(maxSum, abs(minSum));

    }
};