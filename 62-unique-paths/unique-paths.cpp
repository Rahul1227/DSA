class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp){
        if(m <= 0 || n <= 0){
            return 0;

        }

        if(m ==1 && n==1){
            return 1;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int left = solve(m, n-1, dp);
        int up = solve(m-1,n,dp);

        return dp[m][n] = left + up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m,n,dp);
        
    }
};