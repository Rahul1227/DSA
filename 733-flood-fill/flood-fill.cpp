class Solution {
// private:
//     void dfs(int i, int j, vector<vector<int>> &image, int color, int originalColor){
//         int n = image.size();
//         int m = image[0].size();
//         // if(i>n)

//         image[i][j] = color;
//         int dirX[] = {0,0,1,-1};
//         int dirY[] = {1,-1,0,0};

//         for(int k =0; k < 4; k++){
//             int newX = i + dirX[k];
//             int newY = j + dirY[k];
//             if(newX >= 0 && newX < n && newY >=0 && newY < m && image[newX][newY] == originalColor){
//                 dfs(newX, newY, image, color, originalColor);
//             }

//         }

//     }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // //-------------- trying the dfs solution-------------
        

        // if(image[sr][sc] == color) return image;

        // int originalColor = image[sr][sc];
        // dfs(sr,sc,image, color, originalColor);
        // return image;








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