class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        int maxLen = 0;
        int startingPoint = -1;
        
        for(int l = 1; l<=n; l++){
            for(int i=0; i+l-1<n; i++){
                int j = i+l-1;
                if(i == j){
                    dp[i][j] = l;
                }else if(i+1 == j){
                    if(s[i] == s[j]){
                        dp[i][j] = l;
                    }
                }else{
                    if(s[i] == s[j] && dp[i+1][j-1] != 0){
                        dp[i][j] = l;
                    }
                }

                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    startingPoint = i;
                }
            }
        }

        return s.substr(startingPoint, maxLen);

        
    }
};