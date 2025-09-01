class Solution {
private:
    int solve(int l,int r, vector<int>&cuts, vector<vector<int>> &dp){
        if(r-l < 2) return 0; // 1 or less length, the stick cannot be broken

        if(dp[l][r] != -1) return dp[l][r];

        int result = INT_MAX;

        // first and last elements are not the cuts but we added them for our convinence
        for(int ind = l+1; ind <= r-1; ind++){
            int points = cuts[r] - cuts[l] + solve(l, ind,  cuts, dp) + solve(ind, r, cuts, dp);

            result = min(result, points);

        }

        return dp[l][r] = result;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        // sorting to that the values can be solved independently
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0); // inserting 0 at the beginingg for the length calculation
        cuts.push_back(n); // same here, inserting n at the last
        int m = cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1)); // creating 2d dp of m+1 size
        return solve(0,m-1, cuts, dp);
        
    }
};