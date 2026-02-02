class Solution {
private:
    int solve(int ind, int prefixSum, vector<int> &nums, int target){
        int n = nums.size();
        if(ind == n){
            if(prefixSum == target){
                return 1;
            }else{
                return 0;
            }
        }

        int plus = solve(ind+1, prefixSum + nums[ind], nums, target);

        int minus = solve(ind+1, prefixSum - nums[ind], nums, target);

        return plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
        
    }
};