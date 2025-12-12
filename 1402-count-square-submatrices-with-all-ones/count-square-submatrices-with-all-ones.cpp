class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i ==n || j == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(matrix[i][j] != 1) return 0;

        int right = solve(i,j+1, dp,  matrix);
        int down = solve(i+1, j, dp, matrix);
        int daigonal = solve(i+1, j+1, dp, matrix);


        return dp[i][j] = 1 +  min({right, down, daigonal});
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        int total = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                total += solve(i,j,dp,matrix);
            }
        }

        return total;
        
    }
};