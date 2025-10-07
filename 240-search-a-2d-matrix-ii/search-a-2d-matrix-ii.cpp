class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i =0; i<n; i++){
            if(mat[i][m-1] < x || mat[i][0] > x) continue;
            if(binary_search(mat[i].begin(), mat[i].end(),x)){
                return true;
            }
            
        }
        
        return false;

        
    }
};