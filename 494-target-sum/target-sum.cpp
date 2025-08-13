class Solution {
private:
    int solve (int n, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(n == 0){
            if(target == 0){
                return 1;
            } else{
                return 0;
            }
        }
        int targetSize = dp[0].size();
        // if(target + offset < 0 || target + offset >= dp[0].size()) return 0;
        if(dp[n][(target +  targetSize) % targetSize] != -1) return dp[n][(target +  targetSize) % targetSize];

        int plus = solve(n-1, target - nums[n-1], nums,dp);
        int minus = solve(n-1, target + nums[n-1], nums,dp);

        return dp[n][(target +  targetSize) % targetSize] = plus + minus;



    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum;
        int targetSize = sum + abs(target) + 1;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(targetSize, -1));
        return solve (n, target, nums, dp);
        
    }
};