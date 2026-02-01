class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int firstEle = nums[0];
        swap(nums[0], nums[n-1]);
        nums.pop_back();
        sort(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.begin() + 2,0) + firstEle;
        
    }
};