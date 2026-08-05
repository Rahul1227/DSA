class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        vector<long long> suffix(n+1,0);

        for(int i=0; i<n; i++){
            prefix[i+1] = 1LL * (prefix[i] | nums[i]);
        }

        for(int i=n-1; i>=0; i--){
            suffix[i] = 1LL * (suffix[i+1] | nums[i]);
        }

        long long maxSum = 0;
        for(int i=0; i<n; i++){
            long long currSum =1LL * (prefix[i] | suffix[i+1] | (1LL *nums[i]<<k));
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};