class Solution {
private:
    void solve(int ind, vector<int> &curr, vector<vector<int>> &ans, vector<int> &candidates, int target){
        //base case
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }

        // not take;
        solve(ind+1,curr,ans,candidates,target);


        // take
        if(target >=  candidates[ind]){
            curr.push_back(candidates[ind]);
            solve(ind, curr, ans, candidates, target - candidates[ind]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0, curr, ans, candidates, target);
        return ans;
        
    }
};