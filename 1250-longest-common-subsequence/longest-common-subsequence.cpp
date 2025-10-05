class Solution {
private:
    int solve(int i, int j,  string &text1, string &text2, vector<vector<int>> &dp){
        if(i < 0 || j<0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, text1, text2, dp);
        }

        //take
        int first = solve(i-1, j, text1, text2,dp);
        int second = solve(i, j-1, text1, text2, dp);

        return dp[i][j] = max(first, second);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();

        if(len1 == 0 || len2 ==0){
            return 0;
        }

        vector<vector<int>>dp(len1+1, vector<int>(len2+1, -1));
        return solve(len1-1, len2-1, text1, text2, dp);
        
    }
};