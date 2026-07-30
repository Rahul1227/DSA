class Solution {
private:
    int fill(int row, int col, int k, vector<vector<int>> &prefixSum){
        int n = prefixSum.size()-1;
        int m = prefixSum[0].size()-1;

        int leftCol = max(0, col-k);
        int rightCol = min(m-1, col+k);

        int leftRow = max(0, row-k);
        int rightRow = min(n-1, row+k);

        int val = prefixSum[rightRow+1][rightCol+1] - prefixSum[leftRow][rightCol+1] - prefixSum[rightRow+1][leftCol] + prefixSum[leftRow][leftCol];
        return val;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j =1; j<=m; j++){
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = fill(i,j,k, prefix);
            }
        }
        return ans;
        
        
    }
};