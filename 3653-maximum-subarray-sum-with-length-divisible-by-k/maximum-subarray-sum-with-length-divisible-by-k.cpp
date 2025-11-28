class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long maxSum = LLONG_MIN;
       
        int n = nums.size();

        // best approach

        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        // calculating the prefixsum
        for(int i  =1; i<n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        int left = 0;
        int right = 0;

        for(int i = 0; i<k; i++){
            long long currSum = 0;
            left = i;
            while(left+k-1 < n){
                
                right = left+k-1;

                long long sum = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);

                currSum = max(currSum + sum, sum);
                maxSum = max(maxSum, currSum);

                left = left + k;
            }
            

        }

        return maxSum;










        // extreme brute Force
        // for(int i = 0; i<=n-k; i++){
        //     for(int j = i+k-1; j<n; j=j+k){
        //         long long currSum =0;
        //         for(int l =i; l<=j; l++){
        //             currSum += nums[l];
        //         }
        //         maxSum = max(maxSum, currSum);
        //     }
        // }
        // return maxSum;

        // better approach
        //using prefixSum

        // vector<long long> prefixSum(n);
        // prefixSum[0] = nums[0];
        // for(int i = 1; i<n; i++){
        //     prefixSum[i] = nums[i] + prefixSum[i-1];
        // }

        // for(int i =0;  i <n; i++){
        //     for(int j = i; j<n; j++){
        //         int len = j - i + 1;
        //         if(len % k == 0){
        //             long long currSum = 0;
        //         long long left;
        //         if(i>0){
        //             left = prefixSum[i-1];
        //         }else{
        //             left = 0;
        //         }

        //         currSum = prefixSum[j] - left;

        //         maxSum = max(maxSum, currSum);

        //         }
                
        //     }
        // }

        // return maxSum;
        
    }
};