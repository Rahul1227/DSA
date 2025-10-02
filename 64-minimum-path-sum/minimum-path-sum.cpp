class Solution {
private:
    int solve(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> & grid){
        // invalid bound check
        if(i >= n || j >=  m){
            return INT_MAX/3;
        }

        // destination reached
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        // checking the dp
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        

        int right = solve(i,j+1,n,m,dp,grid);
        int down = solve(i+1,j,n,m,dp,grid);

        return dp[i][j] = min(right,down) + grid[i][j];




    }


public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0,0,n,m,dp, grid);

        
    }
};