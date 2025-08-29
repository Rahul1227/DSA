class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<int> &nums){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takeI = nums[i] + min(solve(i+2, j, dp, nums), solve(i+1, j-1, dp, nums));
        int takeJ = nums[j] + min(solve(i+1, j-1, dp, nums), solve(i, j-2, dp, nums));

        return max(takeI, takeJ);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int player1Score = solve(0,n-1, dp, nums);
        int totalPossibleScore = accumulate(nums.begin(), nums.end(),0);
        int player2Score = totalPossibleScore - player1Score;

        return player1Score >= player2Score;

        
    }
};