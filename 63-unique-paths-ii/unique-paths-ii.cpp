class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &grid){
        // Out of bounds
        if(m < 0 || n < 0){
            return 0;
        }
        
        // ⭐ CHECK CURRENT CELL FOR OBSTACLE
        if(grid[m][n] == 1){
            return 0;  // Can't pass through obstacle
        }
        
        // Reached start (0,0)
        if(m == 0 && n == 0){
            return 1;
        }
        
        // Memoization
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        // No need for manual bounds checking - handled by base case
        int left = solve(m, n-1, dp, grid);
        int up = solve(m-1, n, dp, grid);
        
        return dp[m][n] = left + up;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Edge case: start or end blocked
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return 0;
        }
        
        vector<vector<int>> dp(m, vector<int>(n, -1));  // Can be m x n
        return solve(m-1, n-1, dp, grid);
    }
};