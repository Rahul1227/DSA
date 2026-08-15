using t = tuple<int,int,int>;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int maxTime = 0;

        vector<vector<int>> visited(row, vector<int>(col, 0));
        // val, => i,j
        priority_queue<t, vector<t>, greater<>> pq;
        pq.push({grid[0][0], 0,0});
        visited[0][0] =  1;
        int dirX[] = {0,0,1,-1};
        int dirY[] = {-1,1,0,0};

        while(!pq.empty()){
            auto [val, r,c] = pq.top();
            pq.pop();
            maxTime = max(maxTime, val);

            if(r == row-1 && c == col-1){
                return maxTime;
            }

            for(int z=0; z<4; z++){
                int newR = r + dirX[z];
                int newC = c + dirY[z];

                if(newR >=0 && newR < row && newC >=0 && newC < col && !visited[newR][newC]){
                    pq.push({grid[newR][newC], newR, newC});
                    visited[newR][newC] = 1;
                }
            }
        }

        return 0;
        

    }
};