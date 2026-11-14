class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> ans(row, vector<int>(col));
        int dirX[] = {0,0,1,-1};
        int dirY[] = {-1,1,0,0};
        int currDist = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto [r,c] = q.front();
                q.pop();
                ans[r][c] = currDist;

                for(int z=0; z<4; z++){
                    int newR = r + dirX[z];
                    int newC = c + dirY[z];

                    // validation
                    if(newR >= 0 && newR < row && newC >=0 && newC < col && !visited[newR][newC]){
                        q.push({newR, newC});
                        visited[newR][newC] = true;
                    }
                }

            }
            currDist++;
        }

        return ans;
        
    }
};