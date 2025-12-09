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
        vector<vector<bool>> dp(n+1, vector<bool>(n+1));
        // return solve(0, 0, dp, s);

        // doing with tabulation
        dp[n][0] = true;

        for(int ind =  n-1; ind>=0; ind--){
            for(int count =0; count < n; count++){
                 bool isValid = false;

                if(s[ind] == '('){
                    isValid =  dp[ind+1][count+1];
                }else if(s[ind] == ')'){
                    if(count > 0){
                         isValid = dp[ind+1][count-1];
                    }
                   
                }else{
                    bool considerOpen =  dp[ind+1][count+1];
                    bool considerClose = false;
                    if(count > 0){
                        considerClose =  dp[ind+1][count-1];
                    }
                    
                    bool considerNothing = dp[ind+1][count];

                    isValid = considerOpen || considerClose || considerNothing;
                }
                dp[ind][count] = isValid;

            }
        }

        return dp[0][0];



        
    }
};