class Solution {
private:
    void solve(int ind, vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(ind ==nums.size()){
            return;
        }


        // notTake
        solve(ind+1,curr, ans, nums, target);

        // take
        if(target >= nums[ind]){
            target -= nums[ind];
            curr.push_back(nums[ind]);
            solve(ind, curr, ans, nums,target);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, candidates, target);
        return ans;
        
    }
};