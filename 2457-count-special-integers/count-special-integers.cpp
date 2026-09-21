class Solution {
public:
       // ind, tight, started, mask, count
    int dp[12][2][2][1024][12];

    int solve(int ind, bool tight, bool started, int mask, int count, string &num){
        int n = num.size();
        if(ind == n){
            return !count;
        }

        if(dp[ind][tight][started][mask][count] != -1){
            return dp[ind][tight][started][mask][count];
        }

        int limit = (tight ? num[ind] -'0' : 9);
        int result = 0;

        for(int i=0; i<=limit; i++){
            if(i ==0 && !started){
                result += solve(ind+1, false, started,mask,count,num);
            }else{
                int newCount = (count || (mask & (1 << i)));
                int newTight = tight && (i == num[ind]-'0');
                int newMask = (mask | (1 << i));
                result += solve(ind+1, newTight, true, newMask, newCount, num);

            }
        }

        return dp[ind][tight][started][mask][count] = result;
    }

    int countSpecialNumbers(int n) {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0,true,false,0,0, num) - 1;
        
    }
};