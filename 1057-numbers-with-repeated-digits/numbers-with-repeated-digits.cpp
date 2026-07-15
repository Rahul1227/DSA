class Solution {
public:
    //  ind, tight, mask, started, flag
    int dp[11][2][1025][2][2];

    int solve(string &num, int ind, int tight, int mask, int started, int flag){
        // base case
        if(ind == num.size()){
            return flag;
        }

        if(dp[ind][tight][mask][started][flag] != -1){
            return dp[ind][tight][mask][started][flag];
        }

        int limit = (tight ? num[ind] -'0' : 9);
        int ans = 0;

        for(int i =0; i<=limit; i++){
            int updatedTight = (tight && (i == num[ind] -  '0'));
            if(!started && i ==0){
                ans += solve(num, ind+1, updatedTight,0,0,0);
            }else{
                int updatedFlag = flag || (mask & (1 << i));
                int updatedMask = mask | (1 << i);
                ans += solve(num, ind+1, updatedTight, updatedMask, 1, updatedFlag);
            }
        }



        return dp[ind][tight][mask][started][flag] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(num,0,1,0,0,0);
        
    }
};