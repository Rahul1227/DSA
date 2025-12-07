class Solution {
private:
    bool solve(int ind, int target, vector<vector<int>> &dp, vector<int> & nums){
        if(target == 0) return true;

        if(ind < 0) return target == 0;

        if(dp[ind][target] != -1) return dp[ind][target];

        // notTake
        bool notTake = solve(ind -1, target, dp, nums);

        // take
        bool take = false;
        
        if(target >= nums[ind]){
            take  = solve(ind -1 , target - nums[ind], dp, nums);
        }

        return  dp[ind][target] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2 != 0){
            return false;
        }
        int n = nums.size();
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(n-1, target, dp, nums);
        
    }
};