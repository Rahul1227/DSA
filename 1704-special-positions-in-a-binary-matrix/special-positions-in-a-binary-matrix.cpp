class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>> &mat){
        // checking the row
        int n = mat.size();
        int m = mat[0].size();
        for(int col = 0; col  < m;  col++){
            if(col == j) continue;
            if(mat[i][col] == 1) return false;
        }

        // checking the col
        for(int row = 0; row < n; row++){
            if(row == i) continue;
            if(mat[row][j] == 1) return false;
        }

        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j] == 1){
                    if(isValid(i,j,mat)){
                        ans++;
                    }
                }
            }


        }

        return ans;
        
    }
};