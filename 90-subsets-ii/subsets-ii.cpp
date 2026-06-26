class Solution {
private:
    void solve(int ind, vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums){
        // base condition
        if(ind == nums.size()){
            ans.push_back(curr);
            return;
        }

        // take
        curr.push_back(nums[ind]);
        solve(ind+1, curr, ans, nums);
        curr.pop_back();

        // not take
        int newInd = upper_bound(nums.begin() + ind, nums.end(), nums[ind]) - nums.begin();
        solve(newInd, curr, ans , nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0, curr, ans, nums);
        return ans;
        
    }
};