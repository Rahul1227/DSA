class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>> q;
        int dirX[] = {0,0,1,-1};
        int dirY[] = {1,-1,0,0};
        q.push({sr,sc});
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        image[sr][sc] = color;
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            for(int i =0; i<4; i++){
                int newX = r + dirX[i];
                int newY = c + dirY[i];

                // checking the validity;
                if(newX >=0 && newX < n && newY >=0 && newY < m && image[newX][newY] == originalColor){
                    image[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }

        return image;
        
        
    }
};