class Solution {
private:
    int solve(int ind, int canBuy, vector<int> &prices, vector<vector<int>> &dp, int fee){
        int n = prices.size();
        if(ind == n){
            return 0;
        }

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int skip = solve(ind+1, canBuy, prices, dp, fee);

        int profit = 0;
        if(canBuy){
            profit = -prices[ind] + solve(ind+1, 0, prices, dp, fee);
        }else{
            profit = prices[ind] - fee + solve(ind+1, 1, prices, dp, fee);
        }

        return dp[ind][canBuy] = max(skip, profit);
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return solve(0, 1, prices,dp, fee);

        
    }
};