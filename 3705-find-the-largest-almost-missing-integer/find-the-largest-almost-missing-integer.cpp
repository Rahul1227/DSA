class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        if (k == 1) {
            int ans = -1;
            for (auto& [key, val] : mp) {
                if (val == 1 && key > ans) {
                    ans = key;
                }
            }

            return ans;
        } else if(k==n) {
            int ans = -1;
            for (auto& [key, val] : mp) {
                if (key > ans) {
                    ans = key;
                }
            }

            return ans;


        } else {
            int ans = -1;
            int firstElement = nums[0];
            if (mp[firstElement] == 1) {
                ans = max(ans, firstElement);
            }

            int lastElement = nums[n - 1];
            if (mp[lastElement] == 1) {
                ans = max(ans, lastElement);
            }

            return ans;
        }
    }
};