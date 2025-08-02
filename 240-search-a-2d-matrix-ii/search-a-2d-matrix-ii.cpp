class Solution {
// public:
//     bool bs(vector<vector<int>> matrix, int i, int target, int n, int m){
//         int l = 0;
//         int r = m-1;
//         while (l <= r){
//             int mid = (l+r)/2;
//             if(matrix[i][mid] == target){
//                 return true;
//             }else if (matrix[i][mid] < target){
//                 l = mid + 1;
//             }else{
//                 r = mid - 1;
//             }
//         }
//         return false;

//     }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // better but not the optimal approach
        // int n = matrix.size();
        // int m = matrix[0].size();
        // bool result = false;

        // for(int i =0; i<n; i++){
        //     result = bs(matrix, i, target,n, m);
        //     if(result){
        //         return result;
        //     }

        // }
        // return result;




        // ******** Best Solution ************


        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;

        while (row < n && col >=0){
            if(matrix[row][col] == target){
                return true;
            }else if (matrix[row][col] > target){
                col --;
            }else {
                row++;
            }
        }
        return false;

        
        
    }
};