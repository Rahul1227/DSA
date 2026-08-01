class Solution {
private:
    int solve(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &dp){
        int row = mat.size();
        int col = mat[0].size();

        // if(r<0 || c<0) return 0;
        // if(r >= row || c >= col) return 0;


        if(dp[r][c] != -1) return dp[r][c];

        static int dirX[] = {0,0,1,-1};
        static int dirY[] = {-1,1,0,0};

        int maxPath = 0;
        for(int z =0; z<4; z++){
            int newR = r + dirX[z];
            int newC = c + dirY[z];

            if(newR >=0 && newR < row && newC >=0 && newC < col && mat[newR][newC] > mat[r][c]){
                maxPath =max(maxPath, 1 + solve(newR,newC,mat, dp));
            }

        }

        return dp[r][c] = maxPath;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row+1, vector<int>(col+1, -1));
        int maxPath = 0;
        for(int i =0; i<row; i++){
            for(int j = 0; j<col; j++){
                int currPath = solve(i,j,matrix, dp);
                maxPath = max(currPath, maxPath);
            }
        }

        return maxPath+1;
        
    }
};