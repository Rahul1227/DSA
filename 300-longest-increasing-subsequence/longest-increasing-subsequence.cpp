class Solution {
// private:
//     int solve(int ind, int prevInd, vector<vector<int>> &dp, vector<int> &nums){
//         if(ind == nums.size()){
//             return 0;
//         }

//         if(dp[ind][prevInd+1] != -1){
//             return dp[ind][prevInd+1];
//         }

//         // notTake
//         int notTake = solve(ind+1, prevInd, dp, nums);

//         int take = 0;
//         if(prevInd == -1 || nums[ind] > nums[prevInd]){
//             take = 1 + solve(ind+1, ind, dp, nums);
//         }

//         return dp[ind][prevInd+1] = max(notTake, take);
//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        // trying nlogn solution
        int n = nums.size();
        vector<int> lis;

        for(int i =0; i<n; i++){
            int lisSize = lis.size();
            if(lisSize == 0 || lis[lisSize -1] < nums[i] ){
                lis.push_back(nums[i]);
            }else{
                auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
                int ind = it - lis.begin();
                lis[ind] = nums[i];
            }
        }

        return lis.size();












        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return solve(0,-1, dp, nums);
        
    }
};