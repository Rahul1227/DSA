const int MOD = 1e9 + 7;
using pii = pair<int,int>;
// maxSum, PathCount
class Solution {
private:
    pair<int,int> solve(int i, int j, vector<string> &board, vector<vector<pii>> &dp){
        if(i < 0 || j<0 || board[i][j] == 'X') return {INT_MIN, 0};
        if(i ==0 && j == 0){
            return {0,1};
        }

        if(dp[i][j].first != -1) return dp[i][j];

        auto left =  solve(i-1,j,board, dp);
        auto up = solve(i, j-1, board, dp);
        auto diag = solve(i-1, j-1, board, dp);

        int maxSum = max({left.first, up.first, diag.first});
        if(maxSum == INT_MIN){
            return dp[i][j] = {INT_MIN, 0};
        }

        int ways = 0;

        if(left.first == maxSum){
            ways = (ways + (left.second% MOD)) % MOD;
        }

        if(up.first == maxSum){
            ways = (ways + (up.second% MOD)) % MOD;
        }

        if(diag.first == maxSum){
            ways = (ways + (diag.second% MOD)) % MOD;
        }

        maxSum += (board[i][j] != 'S') ? board[i][j] -'0' : 0; 

        return dp[i][j] = {maxSum, ways};

}
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        // maxSum, pathCount
        vector<vector<pii>> dp(n, vector<pii>(n, {-1, 0}));
        auto [maxSum, pathCount] = solve(n-1,n-1, board, dp);
        if(maxSum == INT_MIN){
            return {0,0};
        }

        return {maxSum, pathCount};
        
        
    }
};