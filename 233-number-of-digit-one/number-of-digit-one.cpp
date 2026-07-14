class Solution {
private:    
    int solve(string &s, int ind, int tight, int count, int dp[11][2][11]){
        if(ind == s.size()) return count;

        if(dp[ind][tight][count] != -1) return dp[ind][tight][count];

        int limit = (tight ? s[ind] - '0' : 9);
        int ans = 0;

        for(int i =0; i<=limit; i++){
            int updatedCount = count + (i == 1);
            ans += solve(s, ind+1, (tight & (i == s[ind] - '0')), updatedCount, dp);
        }

        return dp[ind][tight][count] = ans;
    }
public:
    int countDigitOne(int n) {
        int dp[11][2][11];
        memset(dp,  -1,  sizeof(dp));
        string num = to_string(n);
        return solve(num, 0,1,0, dp);


        
    }
};