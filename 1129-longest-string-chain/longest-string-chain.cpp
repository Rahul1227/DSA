class Solution {
private:
    static bool compare(const string &a, const string &b){
        return a.size() < b.size();
    }

    bool findEach(string longer, string tofind){
        for(int i =0; i<longer.size(); i++){
            string newS = longer.substr(0,i) + longer.substr(i+1, longer.size());
            if(newS == tofind){
                return true;
            }
        }
        return false;

    }



    int solve(int ind, int prevInd, vector<vector<int>> &dp, vector<string> &words){
        // base case
        if(ind == words.size()){
            return 0;
        }

        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

        int notTake = solve(ind+1, prevInd, dp, words);

        int take = 0;
        
        if(prevInd == -1 || 
            (words[prevInd].size() + 1 == words[ind].size()
                             && findEach(words[ind], words[prevInd]) )){
            take = 1 + solve(ind+1, ind, dp, words);
        }

        return dp[ind][prevInd+1] = max(take, notTake);
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        for(auto &it : words){
            cout<<it<<" ";
        }
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, dp, words);
    }
};