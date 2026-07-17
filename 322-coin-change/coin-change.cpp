class Solution {
private:
    int solve(int ind, int amount, vector<vector<int>> &dp, vector<int> &coins){
        if(ind == 0){
            if(amount == 0){
                return 0;
            }else{
                return INT_MAX/2;
            }
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int take = INT_MAX/2;
        if(amount >= coins[ind-1]){
            take = 1 + solve(ind, amount-coins[ind-1], dp , coins);
        }

        int noTake = solve(ind-1, amount, dp, coins);

        return dp[ind][amount] = min(take, noTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        // int result = solve(n, amount, dp, coins);

        // return (result >= INT_MAX/2 ? -1 : result);'
        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX/2));
        // dp[0][0] = 0;
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i =1; i<=n; i++){
            for(int currSum = 1; currSum<=amount; currSum++){
                int take = INT_MAX/2;
                if(currSum >= coins[i-1]){
                    take = 1 + dp[i][currSum - coins[i-1]];
                }
                int noTake = dp[i-1][currSum];

                dp[i][currSum] = min(take, noTake);
            }
        }

        int result = dp[n][amount];
        return result >= INT_MAX/2 ? -1 : result;
        
    }
};