class Solution {
private:
    void solve(int ind, int target,int n, vector<int> curr,
     vector<vector<int>> &ans, vector<int> &nums){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        
        if(ind == n){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        // not take
        solve(ind+1,target,n,curr,ans,nums);

        // take
        if(nums[ind] <= target){
            curr.push_back(nums[ind]);
            solve(ind, target - nums[ind], n,curr ,ans, nums);
            curr.pop_back();
        }
        
     }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();
        solve(0,target,n, curr, ans, candidates);
        return ans;
        

    }
};