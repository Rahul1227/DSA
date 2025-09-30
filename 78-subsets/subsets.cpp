class Solution {
private:
    void solve(int ind,vector<int>curr, vector<int> &nums, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(curr);
            return;

        }
        curr.push_back(nums[ind]);
        solve(ind+1, curr, nums, ans);
        curr.pop_back();
        solve(ind+1, curr, nums, ans);
       
    }    

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,curr, nums, ans);
        return ans;
        
    }
};