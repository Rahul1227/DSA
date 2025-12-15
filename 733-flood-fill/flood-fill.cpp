class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];
        vector<vector<int>> visited(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        int dirX[] = {-1,1,0,0};
        int dirY[] ={0,0,1,-1};
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){

                auto [row,col] = q.front();
                q.pop();

                for(int ind =0; ind<4; ind++){
                    int newR = row + dirX[ind];
                    int newC = col + dirY[ind];

                    if(newR >=0 && newR < n && newC >=0 && newC <m && !visited[newR][newC] && image[newR][newC] == originalColor){
                        q.push({newR, newC});
                        image[newR][newC] = color;
                        visited[newR][newC] = 1;
                    }
                }

            }
        }
        return image;
    }
};