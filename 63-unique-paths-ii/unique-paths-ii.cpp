class Solution {
private:
    int solve(int i, int j, int n, int m, vector<vector<int>>& dp,vector<vector<int>> &grid) {
        // base case
        if (i == n - 1 && j == m - 1)
            return 1;

        if (i >= n || j >= m || grid[i][j] == 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // down
        int down = solve(i + 1, j, n, m, dp,grid);

        // right
        int right = solve(i, j + 1, n, m, dp,grid);

        return dp[i][j] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp, obstacleGrid);
    }
};