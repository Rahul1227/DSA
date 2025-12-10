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
        vector<vector<int>> dp(len, vector<int>(len));

        // return solve(1, len-2, dp, cuts);
        
        // trying the tabulation
        for(int i =0; i<len; i++){
            for(int j =0; j<len; j++){
                if(i > j) dp[i][j] =0;
            }
        }

        for(int i = len-2; i>=1; i--){
            for(int j = i; j<len-1; j++){
                int minCost = INT_MAX;
                for(int ind = i; ind <=j; ind++){
                    int currCost  = cuts[j+1] - cuts[i-1] 
                                    + dp[i][ind-1]
                                    + dp[ind+1][j];
                    
                    minCost = min(minCost, currCost);
                }

                dp[i][j] = minCost;

            }
        }
        return dp[1][len-2];
    }
};