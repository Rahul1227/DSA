class Solution {
public:
    int dp[15][2][15];

    int solve(string num, int ind, bool tight, int count){
        int n = num.size();
        if(ind == n){
            return count;
        }
        if(dp[ind][tight][count] != -1) return dp[ind][tight][count];
        int limit = (tight ? num[ind] -'0' : 9);
        int result = 0;
        for(int i =0; i<= limit; i++){
            int newTight = tight & (i == num[ind] -'0');
            int updatedCount = count +  (i == 1);
            result += solve(num, ind+1, newTight, updatedCount);
        }
        return dp[ind][tight][count] = result;
    }
    int countDigitOne(int n) {
        string num = to_string(n);
        memset(dp,-1, sizeof(dp));
        return solve(num, 0, true, 0);
    }
};