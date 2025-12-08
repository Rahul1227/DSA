class Solution {
private:
    int solve(int ind, int prevInd, vector<vector<int>> &dp, vector<int> &nums){
        //base case
        if(ind == nums.size()){
            return 0;
        }

        // dp check
        if(dp[ind][prevInd+1] != -1){
            return dp[ind][prevInd+1];
        }

        // notTake 
        int notTake = solve(ind+1, prevInd, dp, nums);

        //take
        int take = 0;
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            take = 1 + solve(ind+1, ind, dp, nums);

        }
        

        return dp[ind][prevInd+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, dp, nums);
        
    }
};