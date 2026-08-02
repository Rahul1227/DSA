class Solution {
private:
    bool solve(int Alice, int n, vector<vector<int>> &dp){
        if(n <= 0){
            return 1-Alice;
        }

        if(dp[Alice][n] != -1) return dp[Alice][n];
        
        bool result = Alice ? false : true;
        for(int i=1; i<=sqrt(n); i++){
            if(i*i <= n){
                if(Alice){
                    result = result || solve(1-Alice, n-i*i, dp);
                }else{
                    result = result && solve(1-Alice, n-i*i, dp);
                }
                
            }
        }

        return dp[Alice][n] = result;


    }
public:
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(2, vector<int>(n+1, -1));
        return solve(1, n, dp);
        
    }
};