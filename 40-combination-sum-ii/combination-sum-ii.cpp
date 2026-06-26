class Solution {
private:
    void solve(int ind, int target, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans){
    if(ind == nums.size()){
        if(target == 0){
            ans.emplace_back(curr);
        }
        return;
    }

    // take
    if(nums[ind] <= target){
        curr.push_back(nums[ind]);
        solve(ind + 1, target - nums[ind], nums, curr, ans);
        curr.pop_back();
    }

    // not take — skip all duplicates
    ind = upper_bound(nums.begin() + ind, nums.end(), nums[ind]) - nums.begin();
    solve(ind, target, nums, curr, ans);
}

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, curr, ans);
        return ans;
        
    }
};