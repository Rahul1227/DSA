class Solution {
private:
    int solve(int ind1, int ind2, vector<vector<int>> &dp, string &txt1, string &txt2){
        //base case
        if(ind1 < 0 || ind2 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        //both character matching
        if(txt1[ind1] == txt2[ind2]){
            return 1 + solve(ind1-1, ind2-1, dp, txt1, txt2);
        }

        int moveFirst = solve(ind1 -1, ind2, dp, txt1, txt2);
        int moveSecond = solve(ind1, ind2-1, dp, txt1, txt2);


        return dp[ind1][ind2] = max(moveFirst, moveSecond);
    }
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(n-1,n-1,dp,s,s2);


        
    }
};