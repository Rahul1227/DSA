class Solution {
private:
    int solve(int ind, vector<int> &dp, vector<int> &arr, int k){
        if(ind == arr.size()) return 0;

        if(dp[ind]  != -1) return dp[ind];

        int len = 0;
        int maxEle = INT_MIN;
        int maxSum = INT_MIN;
        
        for(int j = ind; j< min((int)arr.size(), ind+k); j++){
            len++;
            maxEle = max(maxEle, arr[j]);

            int currSum = maxEle * len + solve(j+1, dp, arr, k);
            maxSum = max(maxSum, currSum);


        }

        return dp[ind] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n  = arr.size();
        vector<int> dp (n, -1);
        return solve(0, dp, arr, k);
        
    }
};