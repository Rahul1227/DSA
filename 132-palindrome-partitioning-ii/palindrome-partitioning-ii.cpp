class Solution {
private:
    vector<vector<bool>> isPalindrome;
    int solve(int ind, string &s, vector<int> &dp){
        //base case
        int n = s.size();
        if(ind == n){
            return 0;
        }

        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MAX;
        for(int i = ind; i<n; i++){
            if(isPalindrome[ind][i]){
                int curr = 1 + solve(i+1, s, dp);
                ans = min(ans, curr);
            }

        }

        return dp[ind] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        isPalindrome.assign(n, vector<bool>(n, false));

        for(int len = 1; len<=n; len++){
            for(int i=0; i + len -1 < n ; i++){
                int j = i + len -1;

                if( i == j){
                    isPalindrome[i][j] = true;
                }else if( i + 1 == j){
                    isPalindrome[i][j] = s[i] == s[j];
                }else{
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);
                }

            }
        }

        vector<int> dp(n+1, -1);

        return solve(0, s,dp) - 1;
        
    }
};