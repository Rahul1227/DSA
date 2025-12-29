class Solution {
private:
    void solve(vector<int> curr, vector<int>& nums, vector<vector<int>>& ans,
               vector<int> used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                curr.push_back(nums[i]);
                used[i] = 1;
                solve(curr, nums, ans, used);
                //back tracking
                curr.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> used(n, 0);
        vector<int> curr;
        solve(curr, nums, ans, used);
        return ans;
    }
};