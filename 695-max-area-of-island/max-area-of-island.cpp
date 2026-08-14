class Solution {
private:
    int getArea(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
        int row = grid.size();
        int col = grid[0].size();
        int area = 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        static int dirX[] ={0,0,1,-1};
        static int dirY[] = {-1,1,0,0};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            area++;

            for(int z=0; z<4; z++){
                int newR = r + dirX[z];
                int newC = c + dirY[z];

                if(newR >=0 && newR < row && newC >=0 && newC < col && !visited[newR][newC] && grid[newR][newC] == 1){
                    q.push({newR, newC});
                    visited[newR][newC] = 1;
                }
            }
        }
        return area;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        int maxArea = 0;
        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int currArea = getArea(i,j, grid, visited);
                    maxArea = max(maxArea, currArea);

                }
            }
        }

        return maxArea;

        
    }
};