class Solution {
private:
    int solve(int r, int c, vector<vector<int>> &dp, vector<vector<int>> &mat){
        int row = mat.size();
        int col = mat[0].size();

        if(dp[r][c] != -1) return dp[r][c];

        static int dirX[] = {0,0,1,-1};
        static int dirY[] = {-1,1,0,0};
        int result = 1;
        for(int z=0; z<4; z++){
            int newR = r + dirX[z];
            int newC = c + dirY[z];

            if(newR >=0 && newR < row && newC >=0 && newC < col && mat[newR][newC] >mat[r][c]){
                result = max(result, 1 + solve(newR, newC, dp, mat));
            }

        }

        return dp[r][c] = result;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxPath = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));

        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
               
                int currSum = solve(i,j,dp, matrix);
                maxPath = max(maxPath, currSum);
            }
        }

        return maxPath;
        
    }
};