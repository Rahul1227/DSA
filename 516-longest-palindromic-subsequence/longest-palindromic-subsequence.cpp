class Solution {
private:
    int solve(int n1, int n2, vector<vector<int>> &dp, string &txt1, string &txt2){
        if(n1 <0 || n2 < 0) return 0;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(txt1[n1] == txt2[n2]){
            return 1 + solve(n1-1,  n2-1, dp, txt1, txt2);
        }

        // takeFirst
        int takeFirst = solve(n1-1,n2,dp,txt1,txt2);

        //takesecond
        int takeSecond = solve(n1, n2-1, dp, txt1, txt2);

        return dp[n1][n2] = max(takeFirst, takeSecond);
    }



    

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return solve(n-1,n-1,dp,s,s2);
        
    }
};