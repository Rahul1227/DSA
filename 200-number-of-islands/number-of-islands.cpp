class Solution {
private:
    void bfs(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &visited){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            vector<pair<int, int>> dir = {{0,1}, {0,-1},{1,0},{-1,0}};
            for(auto it  : dir){
                auto [i, j] = it;
                int newR = r + i;
                    int newC = c + j;

                    if(newR >= 0 && newR < n && newC >=0 && newC < m && !visited[newR][newC] &&
                     grid[newR][newC] == '1'){
                        q.push({newR, newC});
                        visited[newR][newC] = 1;
                    }
            }

        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        int answer = 0;

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    answer++;
                    bfs(i,j,n,m,grid,visited);
                    
                }
            }
        }
        
        return answer;
        
    }
};