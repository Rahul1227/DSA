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
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(n1-1, n2-1, dp, text1, text2);
        
    }
};