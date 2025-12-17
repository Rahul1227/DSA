class Solution {
private:
    int solve(int ind, int canBuy, vector<int>& prices, int k, vector<vector<vector<int>>> &dp) {
        // base case
        if (ind == prices.size() || k == 0) {
            return 0;
        }
        if(dp[ind][canBuy][k] != -1) return dp[ind][canBuy][k];
        // skipping the current ind
        int notTake = solve(ind+1, canBuy, prices,k,dp);
        int profit = 0;
        if (canBuy) {
            profit =-prices[ind] + solve(ind + 1, 0, prices, k,dp);
        }else{
            profit = prices[ind] + solve(ind+1,1,prices,k-1,dp);
        }
        
        return dp[ind][canBuy][k] = max(profit, notTake);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));

        return solve(0, 1, prices, k, dp);
    }
};