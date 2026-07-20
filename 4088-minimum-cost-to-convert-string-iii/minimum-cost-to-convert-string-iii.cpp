class Solution {
private:
    int solve(int ind,string &source, string &target, vector<vector<string>>& rules, vector<int>& costs, vector<int> &dp){
        //base case
        if(ind == source.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MAX;
        if(source[ind] == target[ind]){
            ans = min(ans, solve(ind+1, source, target, rules, costs, dp));
        }

        for(int z =0; z<rules.size(); z++){
            auto rule = rules[z];
            string src = rule[0];
            string dst = rule[1];
            int len = src.size();
            if(ind + len > source.size()) continue;
            string sourceStr = source.substr(ind, len);
            string targetStr = target.substr(ind, len);
            if(targetStr != dst) continue;
            int starCount =0;
            bool noFound = false;
            for(int i=0; i<len; i++){
                if(src[i] == '*') starCount++;
                if(src[i] != '*' && src[i] != sourceStr[i]){
                    noFound = true;
                    break;
                }
            }
            if(noFound) continue;

            int currCost = costs[z] + starCount;
            int subCall = solve(ind+len,source, target,rules, costs, dp);
            if(subCall >= INT_MAX) continue;
            cout<<src<<" "<<dst<<endl;
            ans = min(ans, currCost + subCall);
            


        }

        return dp[ind] = ans;
    }

public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        if(source == target) return 0;
        vector<int> dp(n+1, -1);
        int result = solve(0,source, target, rules, costs, dp);
        if(result >= INT_MAX) return -1;
        return result;
        
    }
};