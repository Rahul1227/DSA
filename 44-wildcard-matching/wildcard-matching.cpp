class Solution {
private:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //base case
        if(i == 0){
            while(j >0){
                if(p[j-1] != '*') return false;
                j--;
            }
            return true;
        }

        if(j ==0){
            return i ==0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool match = false;
        bool starSkipI = false;
        bool starSkipJ = false;
        bool star = false;

        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        if(p[j-1] == '*'){
            star = solve(i-1, j,s,p,dp);
            // starSkipI = solve(i-1, j-1, s, p, dp);
            starSkipJ = solve(i, j-1, s, p, dp);
        }
        

        return dp[i][j] = star | starSkipJ;
    }
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        // vector<vector<int>> dp(n1+1, vector<int>(n2 + 1, -1));
        vector<vector<bool>> dp(n1+1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for(int k=1; k<=n2; k++){
            int j = k;
            bool result = true;

            while(j>0){
                if(p[j-1] != '*') {
                    result = false;
                    break;
                }
            
                j--;
            }
            dp[0][k] = result;
        }

        for(int i=1; i<=n1; i++){
            for(int j =1; j<=n2; j++){
                if(s[i-1] == p[j-1] || p[j-1] =='?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];

        // return solve(n1, n2, s, p, dp);
        
    }
};