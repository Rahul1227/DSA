class Solution {
public:
    int solve(int n1, int n2, string &txt1, string &txt2, vector<vector<int>> &dp){
        if(n1 == 0 || n2 == 0) return 0;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(txt1[n1-1] == txt2[n2-1]){
            return 1 + solve(n1-1, n2-1, txt1, txt2, dp);
        }

        int firstTake = solve(n1-1, n2, txt1, txt2, dp);
        int secondTake = solve(n1, n2-1, txt1, txt2, dp);

        return dp[n1][n2] = max(firstTake, secondTake);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        if(n1== 0 || n2==0) return 0;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(n1, n2, text1, text2, dp);
        
    }
};