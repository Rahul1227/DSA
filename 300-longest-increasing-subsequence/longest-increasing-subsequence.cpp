class Solution {
private:    
    int solve(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

        int notTake = solve(ind+1, prevInd, nums, dp);

        int take = 0;
        if(prevInd < 0 || nums[prevInd] < nums[ind]){
            take = 1 + solve(ind+1, ind, nums, dp);
        }

        return dp[ind][prevInd+1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0,-1,nums, dp);
        
    }
};