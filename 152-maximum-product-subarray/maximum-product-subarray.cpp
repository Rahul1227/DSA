class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr_max = nums[0], curr_min = nums[0], result = nums[0];

        for (int i = 1; i < n; i++) {
            int temp_max = max({nums[i], curr_max * nums[i], curr_min * nums[i]});
            curr_min = min({nums[i], curr_max * nums[i], curr_min * nums[i]});
            curr_max = temp_max;
            result = max(result, curr_max);
        }

        return result;
    }
};
