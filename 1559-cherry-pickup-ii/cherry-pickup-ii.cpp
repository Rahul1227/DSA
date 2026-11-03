class Solution {
private:
    int solve(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){

        int row = grid.size();
        int col = grid[0].size();

        if(r > row || c1 >= col || c1 < 0 || c2 >= col || c2 < 0){
            return INT_MIN;
        }

        if(r == row){
            return 0;
        }

        if(dp[r][c1][c2] != -1){
            return dp[r][c1][c2];
        }

        int currGain = grid[r][c1];
        if(c1 != c2){
            currGain += grid[r][c2];
        }

        int res = 0;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int curr = solve(r+1, c1+i, c2+j, grid, dp);
                if(curr == INT_MIN) continue;
                res = max(res, curr);
            }
        }

        return dp[r][c1][c2] = res + currGain;



    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row+1, vector<vector<int>>(col+1, vector<int>(col+1, -1)));
        return solve(0, 0, col-1, grid, dp);
        
    }
};