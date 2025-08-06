class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited){
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();

        vector<pair<int,int>> direction  ={{0,1}, {0,-1},{1,0},{-1,0}};
        for(auto [deltai, deltaj] : direction){
                    int nr = row + deltai;
                    int nc = col + deltaj;

                    if(nr >= 0 && nr < n && nc >=0 && nc< m && !visited[nr][nc] && grid[nr][nc] == '1'){
                        q.push({nr,nc});
                        visited[nr][nc] = 1;
                    }
                }
        
            }

        }
    

    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int result =0;

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid,visited);
                    result++;
                }
            }
        }

        return result;
        
    }
};