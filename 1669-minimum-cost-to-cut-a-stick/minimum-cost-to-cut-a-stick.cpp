class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<int> &cuts){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for(int ind = i; ind <=j; ind++){
            int currCost  = cuts[j+1] - cuts[i-1] 
                            + solve(i, ind-1, dp, cuts)
                            + solve(ind+1, j, dp, cuts);
            
            minCost = min(minCost, currCost);
        }

        return dp[i][j] = minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int len = cuts.size();
        vector<vector<int>> dp(len, vector<int>(len, -1));

        return solve(1, len-2, dp, cuts);
        
        
    }
};