class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        int n = s1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i =1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    int skip1 = dp[i-1][j];
                    int skip2 = dp[i][j-1];
                    dp[i][j] = max(skip1, skip2);
                }
            }
        }

        return dp[n][n];
        
    }
};