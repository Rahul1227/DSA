class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

        // trying every possible length
        for(int L = 1; L<=n; L++){
            // trying every starting point
            for(int i =0; i+L-1 < n; i++){
                int j = i+L-1;
                // case 1 -> 1 len
                if(i == j){
                    dp[i][j] = true;
                    // case 2 -> 2 len
                }else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j] == true){
                    count++;
                }
            } 
        }

        return count;
        
    }
};