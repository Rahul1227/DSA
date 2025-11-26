class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp){
        //base condition
        if(m == 0 && n == 0){
            return 1;
        }

        if(m < 0 || n < 0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int up = solve(m-1,n,dp);

        int down = solve(m,n-1,dp);

        return dp[m][n] = up + down;


    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = solve(m-1,n-1,dp);
        return ans;
    }
};