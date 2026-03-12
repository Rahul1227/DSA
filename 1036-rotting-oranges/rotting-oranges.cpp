class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        // finding all the rotten oranges
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] ==1){
                    fresh++;
                }
            }

        }
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        while(!q.empty()){
            int len = q.size();
            for(int i =0; i< len; i++){
                auto [r, c] = q.front();
                q.pop();

                for(int x=0; x<4; x++){
                    int newR = r + dirX[x];
                    int newC = c + dirY[x];
                    if(newR >=0 && newR < m && newC >=0 && newC < n && grid[newR][newC] == 1){
                        grid[newR][newC] = 2;
                        q.push({newR, newC});
                        fresh--;
                    }
                }
            }
            ans++;
            

        }

        if(fresh > 0) return -1;

        return max(ans-1,0);
        
    }
};