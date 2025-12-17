class Solution {
private:
    long long solve(int ind, int currCase,
                    vector<vector<vector<long long>>>& dp, int k,
                    vector<int>& prices) {
        // base case
        if (ind == prices.size()){
            if(currCase == 0) return 0;
            else return INT_MIN;

        }
           

        if (dp[ind][currCase][k] != -1)
            return dp[ind][currCase][k];

        long long skip = solve(ind + 1, currCase, dp, k, prices);

        long long profit = 0LL;
        if (k > 0) {
            if (currCase == 1) {
                profit = prices[ind] + solve(ind + 1, 0, dp, k - 1, prices);
            } else if (currCase == 2) {
                profit = -prices[ind] + solve(ind + 1, 0, dp, k - 1, prices);
            } else {
                profit = max(-prices[ind] + solve(ind + 1, 1, dp, k, prices),
                             prices[ind] + solve(ind + 1, 2, dp, k, prices));
            }
        }

        return dp[ind][currCase][k] = max(skip, profit);
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));
        return solve(0, 0, dp, k, prices);
    }
};