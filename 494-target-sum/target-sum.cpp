class Solution {
private:
    int solve(int ind,int currSum, int offset, int target, vector<int> &nums, vector<vector<int>> &dp ){
        //base case
        if(ind == 0){
            return currSum == target;
        }

        if(dp[ind][currSum + offset] != -1) return dp[ind][currSum + offset];

        int add = solve(ind-1, currSum + nums[ind-1], offset, target, nums, dp);

        int sub = solve(ind-1, currSum - nums[ind-1], offset, target, nums, dp);


        return dp[ind][currSum + offset] = add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int offset = totalSum;
        vector<vector<int>> dp(n+1, vector<int>(2 * totalSum + 2, -1));
        return solve(n,0,offset, target, nums, dp);
    }
};