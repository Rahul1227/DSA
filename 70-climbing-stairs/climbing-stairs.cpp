class Solution {
private:
    int solve(int n, vector<int> &dp){
        if(n < 0) return 0;
        if(n ==0) return 1;

        if(dp[n] != -1) return dp[n];

        // take 1
        int takeOne = solve(n-1, dp);

        // take 2
        int takeTwo = solve(n-2, dp);

        return dp[n] = takeOne + takeTwo;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
        
    }
};