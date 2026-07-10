// using pii = pair<int,int>;
class Solution {
private:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
     
        // base case
        if( j ==0){
            return 1;
        }

        if(i ==0){
            if(j == 0){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][j] != -1) return dp[i][j];

        int skip = solve(i-1, j, s,t, dp);
        int take = 0;
        if(s[i-1] == t[j-1]){
            take = solve(i-1,j-1,s,t,dp);
        }

        return dp[i][j] = skip + take;
    }
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solve(n1, n2, s, t, dp);

        vector<vector<long long>> dp(n1+1, vector<long long >(n2+1, 0));
        for(int i = 0; i<=n1; i++){
            dp[i][0] = 1;
        }

        for(int i =1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                int take =0;
                int skip = 1LL  * dp[i-1][j];
                if(s[i-1] == t[j-1]){
                    take = dp[i-1][j-1];
                }
                dp[i][j] = 1LL * take + skip;
            }
        }

        return (int)dp[n1][n2];
        
    }
};