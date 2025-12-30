class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &mat){
        int n = mat.size();

        if(i >= n || j>=n || j<0){
            return 1e5;
        }
        
        if(i==n-1){
            return mat[i][j];
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int diagonallyLeft = solve(i+1,j-1,dp,mat);
        int diagonallyRight = solve(i+1, j+1, dp, mat);
        int down = solve(i+1,j,dp,mat);


        return dp[i][j] = min({diagonallyLeft, diagonallyRight, down}) + mat[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int minPathSum = INT_MAX;
        for(int j =0; j<n; j++){
            int currPathSum = solve(0,j,dp,matrix);
            minPathSum = min(minPathSum, currPathSum);
        }
        return minPathSum;
        
    }
};