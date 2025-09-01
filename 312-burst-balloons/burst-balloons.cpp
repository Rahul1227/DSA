class Solution {
private:
    int solve(int l, int r, vector<int> &arr, vector<vector<int>> &dp){
        if(l>r) return 0;

        if(dp[l][r] != -1) return dp[l][r];
        int result = INT_MIN;

        for(int ind = l; ind <= r;  ind++){
            int cost = (arr[ind] * arr[l-1] * arr[r+1]) 
                         + solve(l, ind-1,arr,dp) 
                         + solve(ind+1, r, arr, dp);

            result = max(result, cost);
        }

        return dp[l][r] = result;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n-2, nums, dp);
        
    }
};