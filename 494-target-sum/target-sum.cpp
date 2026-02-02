class Solution {
private:
    int solve(int ind, int prefixSum, vector<int> &nums, int target, vector<vector<int>> &dp, int sum){
        int n = nums.size();
        if(ind == n){
            if(prefixSum == target){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[ind][prefixSum + sum] != -1) return dp[ind][prefixSum + sum];

        int plus = solve(ind+1, prefixSum + nums[ind], nums, target, dp,sum);

        int minus = solve(ind+1, prefixSum - nums[ind], nums, target, dp,sum);

        return dp[ind][prefixSum + sum] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(2 * sum+1, -1));
        return solve(0, 0, nums, target, dp, sum);
        
    }
};