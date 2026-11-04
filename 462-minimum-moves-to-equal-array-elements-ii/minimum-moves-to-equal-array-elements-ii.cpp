using ll = long long;
class Solution {
private:
    int getMin(vector<int>&nums, int target){
        int result = 0;
        for(auto num: nums){
            result += abs(num - target);
        }
        return result;
    }
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int half = n/2;
        int res = getMin(nums, nums[half]);
        if(n%2 == 0){
            res = min(res, getMin(nums, nums[half -1]));
        }
        return res;
    }
};