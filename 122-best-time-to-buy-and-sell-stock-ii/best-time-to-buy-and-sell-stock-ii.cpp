class Solution {
private:
    int solve(int ind, int n, int buy, vector<vector<int>> &dp, vector<int> &prices){
        //base condition
        if(ind == n) return 0;


        // memoization step
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;


        if(buy){
            profit = max(-prices[ind] + solve(ind+1,n,0,dp,prices),
                            0 +  solve(ind+1,n,1,dp,prices));

        }else{
            profit = max(prices[ind] +  solve(ind+1,n,1,dp,prices),
                        0 +  solve(ind+1,n,0,dp,prices)
            
            );
        }

        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,  vector<int>(2,-1));
        return solve(0,n, 1,dp,prices);














        // int maxProfit = 0;
        // int n = prices.size();

        // for(int i =1; i<n; i++){
        //     if(prices[i] > prices[i-1]){
        //         maxProfit += prices[i] - prices[i-1];
        //     }
        // }

        // return maxProfit;
        
    }
};