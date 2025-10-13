class Solution {
private:
    int solve(int n, vector<int> &dp, vector<int> &nums){
        if(n < 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        // rob the current
        int curr = nums[n] + solve(n-2,dp,nums);
        // rob the next
        int next = solve(n-1,dp, nums);

        return dp[n] = max(curr,next);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n-1, dp, nums);
        
    }
};