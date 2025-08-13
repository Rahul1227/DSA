class Solution {
private:
    int solve (int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
        // base case
        if(amount == 0) return 1;

        if( n==0) return 0;



        if(dp[n][amount] != -1) return dp[n][amount];

        int noTake = solve(n-1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[n-1]){
            take = solve (n, amount  - coins[n-1], coins, dp);
        }

        return dp[n][amount] = take + noTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(n, amount, coins, dp);
        
    }
};