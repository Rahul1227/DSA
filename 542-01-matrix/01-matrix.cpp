class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        vector<vector<int>> visited(n, vector<int>(m,0));
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,1,-1};
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    visited[i][j] =1;
                    q.push({i,j});
                }
            }
            

        }
        int count =1;
        while(!q.empty()){
            int len = q.size();
            for(int ind=0; ind<len; ind++){
                auto [x,y] = q.front();
                q.pop();

                for(int dir =0; dir<4; dir++){
                    int newX = x + dirX[dir];
                    int newY = y + dirY[dir];
                    if(
                        newX >=0 && newX<n && 
                        newY >=0 && newY < m && 
                        !visited[newX][newY] &&
                        mat[newX][newY] == 1
                    ){
                        ans[newX][newY] = count;
                        q.push({newX, newY});
                        visited[newX][newY] =1;
                    }
                }
            }
            count++;

        }

        return ans;
        
    }
};