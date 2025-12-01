class Solution {
private:
    int solve(int ind, int prevInd, vector<vector<int>> &dp, vector<int> &nums){
        if(ind == nums.size()){
            return 0;
        }

        if(dp[ind][prevInd] != -1){
            return dp[ind][prevInd];
        }

        // notTake
        int notTake = solve(ind+1, prevInd, dp, nums);

        int take = 0;
        if(nums[ind] > nums[prevInd]){
            take = 1 + solve(ind+1, ind, dp, nums);
        }

        return dp[ind][prevInd] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int maxLen = 0;
        for(int i =0; i< nums.size(); i++){
            int len = solve(i,i, dp, nums);
            maxLen = max(maxLen, len);

        }

        return maxLen+1;
        
        
    }
};