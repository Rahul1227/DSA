class Solution {
private:
    int solve(int i, int j, vector<vector<int>>&dp, vector<int> &piles){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takeFirst = piles[i] + min(solve(i+2,j,dp,piles), solve(i+1,j-1, dp,  piles));

        int takeLast = piles[j] + min(solve(i, j-2,  dp, piles), solve(i+1, j-1, dp, piles));

        return dp[i][j] = max(takeFirst, takeLast);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int AliceScore = solve(0, n-1, dp, piles);
        int totalScore = accumulate(piles.begin(), piles.end(), 0);
        int BobScore = totalScore - AliceScore;
        return AliceScore > BobScore;
        
    }
};