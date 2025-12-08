class Solution {
private:
    static bool compare(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> ans;
        int n = envelopes.size();

        for(int i =0; i<n; i++){
            int currLen = ans.size();
            if(currLen == 0 || ans[currLen-1] < envelopes[i][1]){
                ans.push_back(envelopes[i][1]);
            }else{
                auto it = lower_bound(ans.begin(), ans.end(), envelopes[i][1]);
                int ind = it - ans.begin();
                ans[ind] = envelopes[i][1];
            }
        }

        return ans.size();
        
    }
};