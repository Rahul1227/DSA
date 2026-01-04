class Solution {
private:
    void solve(vector<int> &curr, vector<int> &used, vector<vector<int>> &ans, vector<int> &nums){
        //base case
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }


        // exploring all the ways
        for(int i =0;  i< nums.size(); i++){
            if(!used[i]){
                used[i] = 1;
                curr.push_back(nums[i]);
                solve(curr, used, ans, nums);
                used[i] = 0;
                curr.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> used(n, 0);
        solve(curr,used, ans, nums);
        return ans;
        
    }
};