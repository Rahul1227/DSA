class Solution {
private:
    void solve(int ind, vector<int> &curr, int currSum, vector<vector<int>> &ans, int k, int n){
        if(ind > 9){
            if(k ==0 and currSum == n ){
                ans.push_back(curr);
            }
            return;
        }

        // take
        if(currSum + ind <= n){
            curr.push_back(ind);
            solve(ind+1,curr, currSum + ind, ans, k-1, n);
            curr.pop_back();
        }


        // notTake
        solve(ind +1, curr, currSum, ans, k, n);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int currSum =0;
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1,curr, currSum, ans, k, n);
        return ans;
        
    }
};