class Solution {
private:
    int solve(int ind, int canBuy, vector<int> &prices, vector<vector<int>> &dp){
        //base condition
        if(ind >= prices.size()){
            return 0;
        }

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        int profit = 0;

        if(canBuy){
            profit = max(-prices[ind] + solve(ind + 1, 0, prices, dp),
                            0+ solve(ind+1, 1, prices,dp)
            
            );

        }else{
            profit = max(prices[ind]+ solve(ind+2, 1, prices,dp),
                        0 + solve(ind + 1, 0, prices,dp)
            
            );
        }

        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,1,prices,dp);
        
    }
};