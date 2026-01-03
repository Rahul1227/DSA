class Solution {
private:
    int solve(int r, int c1, int c2, vector<vector<vector<int>>>& dp,
              vector<vector<int>>& grid) {
        // base case
        //  bound checks first
        int row = grid.size();
        int col = grid[0].size();

        if (c1 < 0 || c1 >= col || c2 < 0 || c2 >= col){
            return INT_MIN;
        }

        // reaching the last row
        // if(r == row-1){
        //     if(c1 == c2){
        //         return grid[r][c1];
        //     }else{
        //         return grid[r][c1] + grid[r][c2];
        //     }
        // }

        // simple.. think there is one more layer of all zeros
        if(r == row){
            return 0;
        }

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int cherry = grid[r][c1];
        if(c1 != c2){
            cherry += grid[r][c2];
        }

        int maxVal = INT_MIN;
        // checking all the direction possible
        for(int colVal1 = -1; colVal1 <= 1; colVal1++){
            for(int colVal2 = -1; colVal2 <= 1; colVal2++){
                maxVal = max(maxVal, solve(r+1, c1 + colVal1, c2+colVal2, dp,grid));

            }
        }

        if(maxVal != INT_MIN){
            cherry +=maxVal;
        }else{
            cherry = INT_MIN;
        }

        return dp[r][c1][c2] = cherry;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        // row, c1, c2
        vector<vector<vector<int>>> dp(
            row, vector<vector<int>>(col, vector<int>(col, -1)));
        return solve(0, 0, col-1, dp, grid);
    }
};