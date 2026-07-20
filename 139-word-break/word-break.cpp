class Solution {
private:
    bool solve(int ind, string &s, vector<string> &wordDict, vector<int> &dp){
        //base case
        if(ind == s.size()){
            return true;
        }

        if(dp[ind] != -1) return dp[ind];
        bool ans = false;
        for(auto word : wordDict){
            int len = word.size();
            if(ind + len > s.size()) continue;
            string originalStr = s.substr(ind, len);
            if(word == originalStr){
                ans = ans || solve(ind + len, s,wordDict, dp);
            }
        }

        return dp[ind] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, wordDict, dp);
        
    }
};