using pii = pair<int,int>;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pii> q;
        int dirX[] = {0,0,1,-1};
        int dirY[] = {-1,1,0,0};

        vector<vector<int>> ans(m, vector<int>(n, -1));
        int currDistance = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = currDistance;

                }
            }
        }

        currDistance++;

        while(!q.empty()){
            int len = q.size();
            for(int x=0; x<len; x++){
                auto [i, j] = q.front();
                q.pop();

                for(int z =0; z<4; z++){
                    int newI = i + dirX[z];
                    int newJ = j + dirY[z];

                    if(newI >=0 && newI< m && newJ >=0 && newJ <n && ans[newI][newJ] == -1){
                        q.push({newI, newJ});
                        ans[newI][newJ] = currDistance;
                    }
                }

            }
            currDistance++;
        }

        return ans;

        
    }
};