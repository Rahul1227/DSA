using pii = pair<int,int>;
class Solution {
private:
    void bfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pii> q;
        q.push({r,c});
        visited[r][c] = 1;

        static int dirX[] = {0,0,1,-1};
        static int dirY[] = {-1,1,0,0};

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int z =0; z<4; z++){
                int newR = row + dirX[z];
                int newC = col + dirY[z];

                if(newR >=0 && newR < m && newC >=0 && newC < n && !visited[newR][newC] && grid[newR][newC] == '1'){
                    visited[newR][newC] = 1;
                    q.push({newR, newC});
                }

            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i, j, visited, grid);
                    ans++;
                }
            }
            

        }

        return ans;
    }
};