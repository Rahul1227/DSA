class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &tri){
        int n = tri.size();
        
        // Base case: reached last row
        if(i == n-1){
            return tri[i][j];
        }
        
        // Check memoization
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        // Recurrence relation
        int down = solve(i+1, j, dp, tri);
        int downRight = solve(i+1, j+1, dp, tri);
        
        return dp[i][j] = tri[i][j] + min(down, downRight);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(0, 0, dp, triangle);
    }
};