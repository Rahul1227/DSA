class Solution {
private:
    void solve(int ind, vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums, int &target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = ind; i<nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            if(target >= nums[i]){
                curr.push_back(nums[i]);
                target -= nums[i];
                solve(i+1, curr, ans, nums, target);
                curr.pop_back();
                target += nums[i];
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, candidates, target);
        return ans;
        
    }
};