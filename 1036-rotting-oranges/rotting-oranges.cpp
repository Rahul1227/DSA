using pii = pair<int,int>;
class Solution {
private:
     int bfs(queue<pii> &q, int freshCount, vector<vector<int>> &grid, vector<vector<int>> &visited){
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        static int dirX[] = {0,0,1,-1};
        static int dirY[] = {-1,1,0,0};
        while(!q.empty()){
            int len = q.size();
            for(int x=0; x<len; x++){
                auto [i, j] = q.front();
                q.pop();

                for(int z =0; z<4; z++){
                    int newI = i + dirX[z];
                    int newJ = j + dirY[z];

                    if(newI >=0 && newI< m && newJ >=0 && newJ <n && !visited[newI][newJ] && grid[newI][newJ] == 1){
                        freshCount--;
                        q.push({newI, newJ});
                        visited[newI][newJ] = 1;
                    }
                }

                

            }
            count++;
        }
        // cout<<freshCount<<endl;
        // cout<<count<<endl;
        if(freshCount > 0) return -1;
        

        return count-1;
     }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pii> q;
        int freshCount = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) freshCount++;
                else if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = 1;
                }

                
            }
        }
        if(freshCount ==0) return 0;
        return bfs(q, freshCount, grid, visited);
        
    }
};