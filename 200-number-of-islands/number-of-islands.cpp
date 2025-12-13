class Solution {
private:
    void bfs(int i, int j,vector<vector<int>> &visited, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        static vector<int> dirX = {-1,1,0,0};
        static vector<int> dirY ={0,0,1,-1};

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();
            
            
            // iterating in all the directions
            for(int i =0; i<4; i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX >= 0 && newX < n && newY >=0 && newY < m && 
                        visited[newX][newY] == 0 && grid[newX][newY] =='1'){
                
                q.push({newX, newY});
                visited[newX][newY] =1;
                    
                }
            }

            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;


        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    bfs(i,j,visited,grid);
                }

            }
        }

        return count;

        
    }
};