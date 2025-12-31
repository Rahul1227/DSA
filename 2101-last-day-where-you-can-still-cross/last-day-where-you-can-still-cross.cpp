class Solution {
private:
    bool isValid(int totalRow, int totalCol, vector<vector<int>> &temp){
        bool flag1 = false;
        bool flag2 = false;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(totalRow+1, vector<int>(totalCol+1,0));

        for(int col = 1; col <= totalCol; col++){
            if(temp[1][col] == 0){
                flag1 = true;
                q.push({1,col});
                visited[1][col] = 1;
            }

            if(temp[totalRow][col] == 0){
                flag2 = true;
            }
        }

        if(!flag1 || !flag2)  return false;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(x == totalRow) return true;

            int dirX[] = {-1,1,0,0};
            int dirY[] = {0,0,1,-1};

            for(int i =0; i<4; i++){
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX >=1 && newX <= totalRow && newY >= 1 && newY <= totalCol && !visited[newX][newY] && temp[newX][newY] == 0){
                    q.push({newX, newY});
                    visited[newX][newY] = 1;
                }
            }

        }
        return false;
        
        
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int left = 1;
        int right = n;
        int ans = left;
        while(left <= right){
            int mid = left + ((right -left)/2);
            vector<vector<int>> temp(row+1, vector<int>(col+1, 0));
            for(int i =0; i<mid; i++){
                int currRow = cells[i][0];
                int currCol = cells[i][1];
                temp[currRow][currCol] =1;

            }

            if(isValid(row,col,temp)){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid -1;
            }


        }

        return ans;
        
    }
};