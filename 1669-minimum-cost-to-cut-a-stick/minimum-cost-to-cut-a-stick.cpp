class Solution {
private:
    int solve(int l,int r, vector<int>&cuts, vector<vector<int>> &dp){
        if(r-l < 2) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int result = INT_MAX;

        for(int ind = l+1; ind <= r-1; ind++){
            int points = cuts[r] - cuts[l] + solve(l, ind,  cuts, dp) + solve(ind, r, cuts, dp);

            result = min(result, points);

        }

        return dp[l][r] = result;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return solve(0,m-1, cuts, dp);
        
    }
};