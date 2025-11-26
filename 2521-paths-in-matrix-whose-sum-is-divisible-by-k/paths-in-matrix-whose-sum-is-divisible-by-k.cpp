const int MOD = 1e9 + 7;
class Solution {
private:
    int solve(int n, int m, int currSum, vector<vector<vector<int>>> &dp,
     vector<vector<int>> &grid, int k){
        if(n == 0 && m == 0){
            currSum += grid[n][m];
            // cout<<currSum<<endl;
            if(currSum % k == 0){
                return 1;
            }else{
                return 0;
            }
            

        }

        if(n < 0 || m < 0) return 0;

        if(dp[n][m][currSum % k] != -1) return dp[n][m][currSum % k];

        int up = solve(n-1, m, currSum + grid[n][m], dp, grid,k);
        int left = solve(n, m-1, currSum + grid[n][m], dp, grid,k);

        return dp[n][m][currSum % k] = (up + left) % MOD;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k,-1)));
        int currSum = 0;

        int ans = solve(n-1,m-1, currSum, dp,grid,k);
        return ans;
        
    }
};