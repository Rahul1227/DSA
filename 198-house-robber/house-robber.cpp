class Solution {
private:
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int notRob =solve(ind+1, nums, dp);
        int Rob = nums[ind] +solve(ind+2, nums, dp);

        return dp[ind] = max(notRob, Rob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
        
    }
};