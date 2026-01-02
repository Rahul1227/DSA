class Solution {
private:
    void solve(int ind, vector<int> &curr, set<vector<int>> &st, vector<int>  & nums){
        if(ind == nums.size()){
            st.insert(curr);
            return;
        }

        //notTake
        solve(ind+1, curr,st,nums);

        //take
        curr.push_back(nums[ind]);
        solve(ind+1, curr, st, nums);
        curr.pop_back();

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> curr;
        solve(0, curr, st, nums);
        return vector<vector<int>>(st.begin(), st.end());
    
        
    }
};