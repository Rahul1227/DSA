const int MOD = 1e9+7;
class Solution {
private:
    int dp[10004][11][11][6];


    int solve(int ind, int first, int second, int pos, string &s){
        if(pos == 5) return 1;
        int n = s.size();
        if(ind == n) return 0;

        if(dp[ind][first][second][pos] != -1) return dp[ind][first][second][pos];

        int result = 0;
        // skipping the current eleemnt
        result = (result + (solve(ind+1, first, second, pos, s)) % MOD) % MOD;
        
        
        // taking the first element
        if(pos == 0)
            result = (result + (solve(ind+1, s[ind] -'0', second, pos+1, s)) % MOD) % MOD;

        // taking the second element
        if(pos == 1)
            result = (result + (solve(ind+1, first, s[ind] -'0', pos + 1, s)) % MOD) % MOD;

        // taking the third element
        if(pos == 2)
            result = (result + (solve(ind+1, first, second, pos + 1, s)) % MOD) % MOD;
        
        // taking the fourth element
        if(pos == 3 && s[ind] -'0' == second)
            result = (result + (solve(ind+1, first, second, pos + 1, s)) % MOD) % MOD;

        // taking the fifth element
        if(pos == 4 && s[ind] -'0' == first)
            result = (result + (solve(ind+1, first, second, pos + 1, s)) % MOD) % MOD;


        return dp[ind][first][second][pos] = result;
    }

public:
    int countPalindromes(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0,0,0,s);
        
    }
};