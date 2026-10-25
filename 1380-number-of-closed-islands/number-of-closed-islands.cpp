class Solution {
private:
    void bfs(int R, int C, vector<vector<int>> &grid, vector<vector<int>> &visited, bool &isValid){
        int row = grid.size();
        int col = grid[0].size();

        static int dirX[] ={0,0,1,-1};
        static int dirY[] = {-1,1,0,0};
        queue<pair<int,int>> q;
        q.push({R, C});
        visited[R][C]=1;
        

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int z=0; z<4; z++){
                int newR = r + dirX[z];
                int newC = c + dirY[z];


                if(newR < 0 || newR >= row || newC < 0 || newC >= col){
                    isValid = false;
                }

                if(newR >=0 && newR < row && newC >=0 && newC < col && !visited[newR][newC] && grid[newR][newC] == 0){
                    q.push({newR, newC});
                    visited[newR][newC] = 1;

                }
            }
        }


        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col , 0));
        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                    bool isValid = true;
                    bfs(i,j,grid, visited, isValid);
                    if(isValid){
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};