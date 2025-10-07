class Solution {
private:
    void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid){
        queue<pair<int,int>> q;
        int dirX[] = {0,0,-1,1};
        int dirY[] ={-1,1,0,0};
        int n = grid.size();
        int m = grid[0].size();
        q.push({i,j});
        visited[i][j] =1;
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k =0; k<4; k++){
                int newX = i + dirX[k];
                int newY = j + dirY[k];
                if(newX >= 0 && newX < n && newY >=0 && newY < m
                 && !visited[newX][newY] && grid[newX][newY] == '1'){
                    q.push({newX,newY});
                    visited[newX][newY] = 1;

                 }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int n  = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    result++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return result;
        
    }
};