class Solution {
private:
    int solve (int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
       
       if (amount == 0) return 0;
       if( n==0 ) return INT_MAX/2;
        

        if(dp[n][amount] != -1) return dp[n][amount];

        int noTake = 0 + solve(n-1, amount, coins,dp);
        int take = INT_MAX -1 ;

        if(amount >= coins[n-1]){
            take = 1+ solve(n, amount - coins[n-1],coins, dp);
        }
        
        
         

        return dp[n][amount] = min(take, noTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int answer = solve(n, amount, coins, dp);

        return answer >= INT_MAX/2 ? -1 : answer;
        
    }
};