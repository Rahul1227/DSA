class Solution {
public:
    int fill(int row, int col, int k, vector<vector<int>> &prefixSum){
        // cout<<"inside thhe fll"<<endl;
        int n = prefixSum.size();
        int m = prefixSum[0].size() - 1;
        int leftCol = max(0,  col - k);
        int rightCol = min(m-1, col+k);

        int upRow = max(0, row -k);
        int downRow = min(n-1, row + k);

        int totalSum =0;
        for(int i = upRow; i<= downRow; i++){
            totalSum += prefixSum[i][rightCol+1] - prefixSum[i][leftCol];
        }
        // cout<<totalSum<<endl;
        return totalSum;
        
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
         // Your code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefixSum[i][j+1] = prefixSum[i][j] + mat[i][j];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans [i][j] = fill(i,j,k,prefixSum);
                // cout<<ans[i][j]<<endl;
            }
        }
        return ans;
    }
        
    
};