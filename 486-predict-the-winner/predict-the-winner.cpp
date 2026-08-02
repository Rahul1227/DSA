class Solution {
private:
    long long solve(int i, int j, vector<vector<long long>> &dp, vector<int> &nums){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int takeI = nums[i] + min(solve(i+2, j, dp, nums), solve(i+1, j-1, dp, nums));

        int takeJ = nums[j] + min(solve(i, j-2, dp, nums), solve(i+1, j-1, dp, nums));

        return dp[i][j] = max(takeI, takeJ);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long result = solve(0, n-1, dp, nums);
        return 2* result >= totalSum;

    }
};