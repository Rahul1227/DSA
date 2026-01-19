class Solution {
private:
    bool isValid(int x1, int y1, int x2, int y2, vector<vector<int>> &prefixSum, int threshold){
        int sum = prefixSum[x2+1][y2+1] - prefixSum[x1][y2+1] 
                            - prefixSum[x2+1][y1] + prefixSum[x1][y1];
        return sum <= threshold;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        //prefixSUm
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1,0));

        for(int i =0; i<m; i++){
            for(int j=0; j<n; j++){
                prefixSum[i+1][j+1] = prefixSum[i][j+1] + prefixSum[i+1][j] 
                                        - prefixSum[i][j] + mat[i][j];
            }
        }

        for(int side = min(m,n); side >0; side--){
            for(int i=0; i + side -1<m; i++){
                for(int j=0; j + side - 1<n; j++){
                    int k = i+side-1;
                    int l = j+side-1;

                    if(isValid(i,j,k,l,prefixSum, threshold)){
                        return side;
                    }
                }
            }
        }

        return 0;
        
    }
};