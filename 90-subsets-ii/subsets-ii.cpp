class Solution {
private:
    void solve(int ind, vector<int> &curr, vector<vector<int>>&ans, vector<int> &nums){
        // push at each level
        ans.push_back(curr);

        for(int i = ind; i< nums.size(); i++){
            // trying to skip the duplicate
            if(i != ind && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            solve(i+1, curr, ans, nums);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, nums);
        return ans;
        
    }
};