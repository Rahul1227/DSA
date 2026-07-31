class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftInd = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(leftInd == n || nums[leftInd] != target){
            return {-1,-1};
        }
        int rightInd = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        rightInd--;
        return {leftInd, rightInd};
        
    }
};