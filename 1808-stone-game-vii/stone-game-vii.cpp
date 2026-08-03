class Solution {
private:
    int solve(int i, int j,vector<int> &prefixSum, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }


        if(dp[i][j] != -1) return dp[i][j];

        int takeFirst = prefixSum[j+1] - prefixSum[i+1] - solve(i+1, j, prefixSum, dp);

        int takeLast = prefixSum[j] - prefixSum[i] - solve(i, j-1, prefixSum, dp);
        return dp[i][j] = max(takeFirst, takeLast);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n+1, 0);
        
        for(int i =0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + stones[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int diff = solve(0,n-1, prefixSum, dp);
        // int BobScore = prefixSum[n] - AliceScore;
        return diff;
    }
};