class Solution {
public:
    int solve(int n1, int n2, string &txt1, string &txt2, vector<vector<int>> &dp){
        if(n1 == 0 || n2==0) return 0;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(txt1[n1-1] == txt2[n2-1]){
            return 1 + solve(n1-1, n2-1, txt1, txt2, dp);
        }

        int firstTake = solve(n1-1, n2, txt1, txt2, dp);
        int secondTake = solve(n1, n2-1, txt1, txt2, dp);

        return dp[n1][n2] = max(firstTake, secondTake);
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string b = s;
        reverse(b.begin(), b.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, n, s, b, dp);
        
    }
};