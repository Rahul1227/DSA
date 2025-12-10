class Solution {
private:
    int solve(int i, int j, vector<vector<int>>  &dp, vector<int> &nums){
        //base case
        if(i > j) return 0;

        // checking if the answer is already computed
        if(dp[i][j] != -1) return dp[i][j];

        // for making the subproblems independent, we will be starting from the bottom
        int maxCoins = INT_MIN;
        for(int ind = i; ind <= j; ind++){
            int currCoin = nums[i-1] * nums[ind] * nums[j+1]
                            + solve(i, ind-1, dp, nums)
                            + solve(ind+1, j, dp , nums);

            maxCoins = max(maxCoins,currCoin);
        }
        return dp[i][j] = maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n+2,1);
        for(int i = 1; i<=n; i++){
            newNums[i] = nums[i-1];
        }


        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(1,n, dp, newNums);
        
    }
};