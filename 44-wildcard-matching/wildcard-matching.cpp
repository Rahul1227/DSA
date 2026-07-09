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
            match = solve(i-1, j-1, s, p, dp);
        }
        if(p[j-1] == '*'){
            star = solve(i-1, j,s,p,dp);
            starSkipI = solve(i-1, j-1, s, p, dp);
            starSkipJ = solve(i, j-1, s, p, dp);
        }
        

        return dp[i][j] = match | star | starSkipI | starSkipJ;
    }
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2 + 1, -1));

        return solve(n1, n2, s, p, dp);
        
    }
};