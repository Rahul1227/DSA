class Solution {
private:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(j-i<=1){
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int result = INT_MAX;

        for (int ind = i + 1; ind < j; ind++) {
            result = min(
                result,
                cuts[j] - cuts[i]
                + solve(i, ind, cuts, dp)
                + solve(ind, j, cuts, dp)
            );
        }

        return dp[i][j] = result;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(0, m - 1, cuts, dp);
    }
};