class Solution {
private:
    int solve(int i, int j, vector<int> &stones, vector<int> &prefixSum, vector<vector<int>> &dp){
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        int totalSum = prefixSum[j+1] - prefixSum[i];
        int result = 0;
        for(int k = i; k<j; k++){
            int leftSum = prefixSum[k+1] - prefixSum[i];
            int rightSum = totalSum - leftSum;
            if(leftSum < rightSum){
                result = max(result, leftSum + solve(i, k,stones, prefixSum,dp));
            }else if(rightSum < leftSum){
                result = max(result, rightSum + solve(k+1, j, stones, prefixSum, dp));
            }else{
                 result = max({result, leftSum + solve(i, k,stones, prefixSum,dp), rightSum + solve(k+1, j, stones, prefixSum, dp)});
            }
        }

        return dp[i][j] = result;

           
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        vector<int> prefixSum(n+1, 0);

        for(int i=0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + stoneValue[i];
        }

        return solve(0,n-1, stoneValue, prefixSum, dp);
        
    }
};