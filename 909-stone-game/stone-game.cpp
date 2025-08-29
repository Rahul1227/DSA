class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<int> &nums){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int takeI = nums[i] + min(solve(i+2, j,dp,nums), solve(i+1, j-1,dp, nums));
        int takeJ = nums[j] + min(solve(i+1, j-1, dp, nums), solve(i, j-2, dp, nums));

        return dp[i][j]=max(takeI, takeJ);
    }


public:
    int stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int AliceScore =  solve(0, n-1, dp, piles);
        int totalPossibleScore = accumulate(piles.begin(), piles.end(), 0);
        int BobScore = totalPossibleScore - AliceScore;
        return AliceScore > BobScore;
        
    }
};