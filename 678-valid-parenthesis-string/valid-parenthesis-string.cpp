class Solution {
private:
    bool solve(int ind, int count, vector<vector<int>> &dp, string &s){
        //base case
        if(count < 0){
            return false;
        }


        if(ind == s.size()){
            return count == 0;
        }

        if(dp[ind][count] != -1){
            return dp[ind][count];
        }

        bool isValid = false;

        if(s[ind] == '('){
            isValid =  solve(ind+1, count+1, dp, s);
        }else if(s[ind] == ')'){
            isValid = solve(ind+1, count -1, dp, s);
        }else{
            bool considerOpen =  solve(ind+1, count+1, dp, s);
            bool considerClose =  solve(ind+1, count-1, dp, s);
            bool considerNothing =  solve(ind+1, count, dp, s);

            isValid = considerOpen || considerClose || considerNothing;
        }

        return dp[ind][count] = isValid;

    }
public:
    bool checkValidString(string s) {
        int  n = s.size();
        vector<vector<int>> dp(n,  vector<int>(n+1, -1));
        return solve(0, 0, dp, s);
        
    }
};