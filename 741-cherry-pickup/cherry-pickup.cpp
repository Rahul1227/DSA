class Solution {
private:
    int solve(int r1, int c1, int r2, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        // base case
        // r1 + c1 = r2 + c2 == > c2 = r1 + c1 -r2
        int c2 = r1 + c1 - r2;
        int n = grid.size();

        // invalid path
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return INT_MIN;
        }

        // reaching the end -->both the robots
        if (r1 == n - 1 && c1 == n-1){
            return grid[r1][c1];
        }

        // checking if the value exist in the dp
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        //adding the curent values
        int cherries = grid[r1][c1];
        if(r1 != r2){
            cherries += grid[r2][c2];
        }

        //checking all the 4 directions
        int maxValue = INT_MIN;
        // right , right
        maxValue = max(maxValue, solve(r1, c1+1, r2,grid, dp));
        //right, down
        maxValue = max(maxValue, solve(r1, c1 + 1, r2 + 1,grid, dp));
        // down , right
        maxValue = max(maxValue, solve(r1 + 1, c1, r2,grid, dp));
        // down , down
        maxValue = max(maxValue, solve(r1 + 1, c1, r2 + 1,grid, dp));

        if(maxValue != INT_MIN){
            cherries += maxValue;
        }else{
            cherries = INT_MIN;
        }

        return dp[r1][c1][r2] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, -1)));
        // r1,c1,r2
        int ans = solve(0, 0, 0, grid, dp);
        return max(ans,0);
    }
};