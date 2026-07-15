class Solution {
public:
    int dp[11][2][1030][2];

    int solve(string &num, int ind, int tight, int mask, int started){
        //base case
        if(ind == num.size()){
            return 1;
        }

        if(dp[ind][tight][mask][started] != -1) return dp[ind][tight][mask][started];

        int limit = (tight ? num[ind] -'0' : 9);
        int ans =0;
        for(int i=0; i<=limit; i++){
            int updatedTight = (tight & (i == num[ind] -'0'));
            if(!started && i ==0){
                ans += solve(num, ind+1, updatedTight, 0, 0);
            }else{
                if((mask & (1 << i)) == 0){
                    int updatedMask = mask | (1 << i);
                    ans += solve(num, ind+1, updatedTight, updatedMask, 1);
                }
            }
        }

        return dp[ind][tight][mask][started] = ans;
    }

    int countSpecialNumbers(int n) {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(num, 0, 1, 0, 0) - 1;
        
    }
};