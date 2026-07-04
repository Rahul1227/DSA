class Solution {
public:
    string longestPalindrome(string s) {
        int startingPoint = 0;
        int maxLen = 1;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int l =1; l<=n; l++){
            for(int i =0; i+l-1 <n; i++){
                int j = i+l-1;

                if(i ==j){
                    dp[i][j] = l;
                }else if(i+1 == j){
                    if(s[i] == s[j]){
                        dp[i][j] = l;
                    }
                }else{
                    if(s[i] == s[j] && dp[i+1][j-1] != -1){
                        dp[i][j] = l;
                    }
                }

                if(maxLen < dp[i][j]){
                    maxLen = dp[i][j];
                    startingPoint = i;
                }
            }
        }

        return s.substr(startingPoint, maxLen);
        
    }
};