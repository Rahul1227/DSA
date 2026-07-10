class Solution {
private:
    bool getAnswer(int j, string& p) {
        while (j > 0) {
            if (p[j - 1] != '*')
                return false;
            j = j - 2;
        }
        return true;
    }

    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // base case
        if (i == 0) {
            return getAnswer(j, p);
        }

        if (j == 0) {
            return i == 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        bool skipI = false;
        bool skipJ = false;

        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        } else if (p[j - 1] == '*') {
            if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                skipI = solve(i - 1, j, s, p, dp);
            }
            skipJ = solve(i, j - 2, s, p, dp);
            return dp[i][j] = skipI || skipJ;

        } else {
            return dp[i][j] = false;
        }
    }

public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        // vector<vector<int>> dp(n1+1,vector<int>(n2+1, -1));
        // return solve(n1, n2, s, p, dp);
        // vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        vector<bool> prev(n2+1, false);
        vector<bool> curr(n2+1, false);
        // dp[0][0] = true;
        for (int j = 1; j <= n2; j++) {
            prev[j] = getAnswer(j, p);
        }
        prev[0] = true;


        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                bool skipI = false;
                bool skipJ = false;

                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    curr[j] = prev[j-1];
                } else if (p[j - 1] == '*') {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        skipI = prev[j];
                    }
                    skipJ = curr[j-2];
                    curr[j] = skipI || skipJ;
                }else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};