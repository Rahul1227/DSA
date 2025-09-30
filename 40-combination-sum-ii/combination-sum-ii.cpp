class Solution {
private:
    void solve(int ind, int target, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;

            if(nums[i] > target) break;

            //take
            curr.push_back(nums[i]);
            solve(i+1, target - nums[i], nums, curr, ans);
            curr.pop_back();
        }
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