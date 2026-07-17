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
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int result = solve(n, amount, dp, coins);

        return (result >= INT_MAX/2 ? -1 : result);
        
    }
};