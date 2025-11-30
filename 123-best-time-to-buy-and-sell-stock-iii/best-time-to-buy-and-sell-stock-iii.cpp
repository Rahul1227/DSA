class Solution {
private:
    int solve(int ind, int canBuy, int leftChances, 
    vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || leftChances == 0){
            return 0;
        }

        if(dp[ind][canBuy][leftChances] != -1){
            return dp[ind][canBuy][leftChances];
        }
        int profit;

        if(canBuy){
            profit = max(-prices[ind] + solve(ind+1, 0, leftChances, prices,dp),
                            0 + solve(ind+1,1,leftChances,prices,dp)
            
            );

        }else{
            profit = max(prices[ind] + solve(ind + 1, 1, leftChances-1,prices,dp),
                        0+ solve(ind+1, 0, leftChances,prices,dp)
            
            );
        }

        return dp[ind][canBuy][leftChances] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
        
        
    }
};