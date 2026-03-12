class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        // top row and bottom row
        for(int col = 0; col <n; col++){
            if(grid[0][col] == 1){
                q.push({0, col});
                grid[0][col] = 0;
            }

            if(grid[m-1][col] == 1){
                q.push({m-1, col});
                grid[m-1][col] = 0;
            }
        }

        // first and last col
        for(int row =0; row < m; row++){
            if(grid[row][0] == 1){
                grid[row][0] = 0;
                q.push({row, 0});
            }

            if(grid[row][n-1] == 1){
                grid[row][n-1] = 0;
                q.push({row, n-1});
            }
        }
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int x =0; x<4; x++){
                int newR = r + dirX[x];
                int newC = c + dirY[x];

                if(newR >=0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1){
                    grid[newR][newC] = 0;
                    q.push({newR, newC});
                }
            }

        }

        int ans = 0;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;
        
    }
};