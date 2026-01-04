class Solution {
private:
    bool solve(int ind, string s, unordered_set<string> &st, vector<int> &dp){
        //base case
        if(ind == s.size()){
            return true;
        }

        if(dp[ind] != -1) return dp[ind];

        string temp = "";
        for(int i = ind; i< s.size(); i++){
            temp += s[i];
            if(st.count(temp)){
                if(solve(i+1,s,st,dp)) return dp[ind] = true;
            }

        }
        return dp[ind] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // creating a set of the dict words
        unordered_set<string> st;
        for(auto word : wordDict){
            st.insert(word);
        }

        int n = s.size();
        vector<int> dp(n, -1);

        if(solve(0, s, st, dp)){
            return true;
        }
        return false;
        
    }
};