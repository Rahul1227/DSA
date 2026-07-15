using piii = pair<int, pair<int,int>>;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({0,{0,0}});
        int dirX[] = {0,0,1,-1};
        int dirY[] = {-1,1,0,0};
        int ans = 0;
        while(!pq.empty()){
            auto topEle = pq.top();
            pq.pop();
            int weight = topEle.first;
            int i = topEle.second.first;
            int j = topEle.second.second;
            if(visited[i][j]) continue;
            ans = max(ans, weight);
            if( (i == row-1) && (j == col-1)) return ans;

            

            visited[i][j] = 1;
           

            for(int z =0; z<4; z++){
                int newI = i + dirX[z];
                int newJ = j + dirY[z];

                if(newI >=0 && newI < row && newJ >=0 && newJ < col && !visited[newI][newJ]){
                    int cost = abs(heights[i][j] - heights[newI][newJ]);
                    pq.push({cost, {newI, newJ}});
                }
            }
        }
        return ans;
        
    }
};