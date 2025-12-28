class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalNegative = 0;

        // more optimized way
        int i = n-1;
        int j = 0;
        while(i>=0 && j<m){
            if(grid[i][j] < 0){
                totalNegative += m-j;
                i--;
            }else{
                j++;
            }
        }

        // for(int i =0; i<n; i++){
        //     int left = 0;
        //     int right = m-1;
        //     int currNegativeInd = -1;
        //     while(left <= right){
        //         int mid = left + ((right -left)/2);
        //         if(grid[i][mid] < 0){
        //             currNegativeInd = mid;
        //             right = mid -1;
        //         }else{
        //             left = mid + 1;
        //         }
        //     }

        //     if(currNegativeInd != -1){
        //         totalNegative += m - currNegativeInd;
        //     }
        // }

        return totalNegative;        
    }
};