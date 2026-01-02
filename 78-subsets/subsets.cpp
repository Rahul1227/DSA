class Solution {
private:
    void solve(int ind, vector<int> curr, vector<vector<int>>& ans,
               vector<int>& nums) {
                
                if(ind == nums.size()){
                    ans.push_back(curr);
                    return;
                }

                // notTake
                solve(ind+1, curr, ans, nums);

                //take
                curr.push_back(nums[ind]);
                solve(ind+1, curr, ans, nums);


               }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, nums);
        return ans;
    }
};