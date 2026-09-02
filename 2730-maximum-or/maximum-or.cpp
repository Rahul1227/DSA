class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1);
        vector<long long> suffix(n+1);
        prefix[0] = 0;
        suffix[n] = 0;

        // calculating the prefix
        for(int i=0; i<n; i++){
            prefix[i+1] = 1LL * prefix[i] | nums[i];
        }

        // calculating the suffix
        for(int i=n-1; i>=0; i--){
            suffix[i] = 1LL * suffix[i+1] | nums[i];
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long tempval = (1LL * nums[i]<<k);
            long long currVal = 1LL * prefix[i] | tempval | suffix[i+1];
            ans = max(ans, currVal);
        }
        return ans;
        
    }
};