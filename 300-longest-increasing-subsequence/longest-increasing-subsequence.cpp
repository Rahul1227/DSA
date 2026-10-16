class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int maxLen = 1;

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        maxLen = max(maxLen, dp[i]);
                    }
                }
            }
        }

        return maxLen;
        
    }
};