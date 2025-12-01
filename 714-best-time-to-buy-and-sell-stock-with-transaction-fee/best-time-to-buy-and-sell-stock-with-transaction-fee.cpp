class Solution {
private:
    int solve(int ind, int canBuy, int fee, vector<vector<int>>&dp, vector<int> &prices){
        //base case
        if(ind == prices.size()){
            return 0;
        }

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        int profit = 0;

        if(canBuy){
            profit = max(-prices[ind] + solve(ind+1, 0, fee, dp, prices),
                            0 + solve(ind+1, 1, fee, dp, prices)
            );


        }else{
            profit = max(prices[ind] - fee + solve(ind+1, 1, fee, dp, prices),
                        0 + solve(ind+1,0, fee, dp, prices)
            
            );
        }

        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,1,fee,dp,prices);
        
    }
};