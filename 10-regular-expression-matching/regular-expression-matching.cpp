class Solution {
private:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        // base case
        if(i ==0){
            while(j>0){
                if(p[j-1] != '*') return false;
                j = j-2;
            }
            return true;
        }

        if(j==0){
            return i ==0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool skipI = false;
        bool skipJ = false;

        if(s[i-1] == p[j-1] || p[j-1] == '.'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }else if(p[j-1] == '*'){
            if(p[j-2] == s[i-1] || p[j-2] == '.'){
                skipI = solve(i-1,j,s,p,dp);
            }
            skipJ = solve(i, j-2, s, p, dp);
            return dp[i][j] = skipI || skipJ;
            
        }else{
            return dp[i][j] = false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1, -1));
        return solve(n1, n2, s, p, dp);
        
    }
};