class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // jai mata ji
        // jai baranj bali
        int n = grid.size();
        int m = grid[0].size();

        int level  = 0;
        queue<pair<int,pair<int,int>>> q;

        // the directions are 
        int dirX[] = {0, 1,0,-1};
        int dirY[] = {-1,0,1,0};

        // trying multi-source bfs
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({level,{i,j}});
                }
            }
        }

        while(!q.empty()){
            int  z = q.size();
            for(int i =0; i<z; i++){
                auto node = q.front();
                int lev = node.first;
                int x = node.second.first;
                int y = node.second.second;
                q.pop();
                level = lev;
                for(int j =0; j<4; j++){
                    int newX = x + dirX[j];
                    int newY = y + dirY[j];
                    
                    // validity check
                    if(newX >=0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        q.push({lev + 1,{newX, newY}});
                    }
                }
            }
        }

        for(int i =0;  i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return level;



        
    }
};