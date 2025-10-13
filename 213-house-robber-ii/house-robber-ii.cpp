class Solution {
private:
    int solve(int start, int end, vector<int> &dp, vector<int> &nums){
        if(start > end){
            return 0;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        // rob current
        int curr = nums[start] + solve(start + 2, end, dp ,nums);

        // rob next
        int next = solve(start + 1, end, dp, nums);

        return dp[start] = max(curr,next);

    }
public:
    int rob(vector<int>& nums) {
        // here the main catch is that , the first and the last house are adjacent
        // so either to rob from 0 to n-2
        // or to rob 1 to n-1
        int n = nums.size();
        if(n==1) return nums[0];


        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int noLast = solve(0,n-2,dp1,nums);
        int noFirst = solve(1,n-1,dp2,nums);

        return max(noLast, noFirst);

        
    }
};