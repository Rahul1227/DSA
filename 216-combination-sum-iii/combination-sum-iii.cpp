class Solution {
private:
    void solve(int ind, vector<int> &curr, vector<vector<int>> &ans, int k, int n){
        //base case
        if(k == 0){
            if(n==0){
                ans.push_back(curr);
                return;
            }else{
                return;
            }
        }

        for(int i = ind; i<=9; i++){
            if(n >= i){
                curr.push_back(i);
                solve(i+1,curr, ans,k-1,n-i);
                curr.pop_back();
            }
        }



    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(1, curr, ans,  k,  n);
        return ans;
        
    }
};