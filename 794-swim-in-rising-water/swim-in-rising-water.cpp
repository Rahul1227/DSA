class Solution {
private:
    bool isPossible(int r, int c,int mid, vector<vector<int>> &grid, vector<vector<int>> &visited){
        if(grid[r][c] > mid){
            return false;
        }
        int row = grid.size();
        int col = grid[0].size();

        if( r == row-1 && c == col-1){
            return true;
        }

        visited[r][c] = 1;
        


        static int dirX[] = {0,0,1,-1};
        static int dirY[] = {-1,1,0,0};

        

        for(int z=0; z<4; z++){
            int newR = r + dirX[z];
            int newC = c + dirY[z];

            if(newR >=0 && newR < row && newC >=0 && newC < col && !visited[newR][newC]){
                if(isPossible(newR, newC,mid,grid, visited)) return true;
            }


        }
        // visited[r][c] =0;

        return false;


    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int l = grid[0][0];
        int r = INT_MIN;

        int row = grid.size();
        int col = grid[0].size();

        

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                // l = min(l, grid[i][j]);
                r = max(r, grid[i][j]);
            }
        }

        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<vector<int>> visited(row, vector<int>(col, 0));
            if(isPossible(0,0,mid, grid, visited)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
        
    }
};