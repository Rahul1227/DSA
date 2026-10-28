class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bitset<1024>>> dp(row, vector<bitset<1024>>(col));
        dp[0][0].set(grid[0][0]);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i == 0 && j == 0) continue;
                bitset<1024> up, left;
                if(i>0){
                    up = dp[i-1][j];
                }

                if(j>0){
                    left = dp[i][j-1];
                }

                bitset<1024> finalVals= up | left;
                

                for(int k=0; k<1024; k++){
                    if(finalVals[k]){
                        int currXor = grid[i][j] ^ k;
                        dp[i][j].set(currXor);
                    }
                }


            }
        }

        bitset<1024> finalSet = dp[row-1][col-1];
        // int ans = -1;
        for(int k=0; k<1024; k++){
            if(finalSet[k]){
                return k;
            }
        }
        
        

        return -1;
    }
};