class Solution {
private:
    bool solve(int i, int j,string &s, vector<vector<int>> &dp){
        if(i>=j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            dp[i][j] = solve(i+1, j-1, s, dp);
        }else{
            dp[i][j] = false;
        }
        return dp[i][j];

    }



public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int maxlen = 0;
        int startPoint = 0;

        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                if(solve(i,j,s,dp)){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }

        return s.substr(startPoint, maxlen);

        
    }
};