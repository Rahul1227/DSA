class Solution {
private:
    int solve(int ind, int rem, vector<vector<int>>& dp, vector<int>& nums) {
        if (ind < 0) {
            return rem == 0 ? 0 : INT_MIN;
        }

        if (dp[ind][rem] != -1) return dp[ind][rem];

        int take = nums[ind] + solve(ind - 1, (rem + nums[ind]) % 3, dp, nums);
        int skip = solve(ind - 1, rem, dp, nums);

        return dp[ind][rem] = max(take, skip);
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));

        int ans = solve(n - 1, 0, dp, nums);
        return ans < 0 ? 0 : ans;
    }
};
