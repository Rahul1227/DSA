const int MOD = 1e9 + 7;
class Solution {
public:
    // ind, tight, started, prev
    long long dp[102][2][2][12];

    long long solve(string &num, int ind, int tight, int started, int prev){
        if(ind == num.size()){
            return 1;
        }

        if(dp[ind][tight][started][prev+1] != -1){
            return dp[ind][tight][started][prev+1];
        }

        int limit = (tight ? num[ind] -'0' : 9);
        long long ans = 0;

        for(int i=0; i<=limit; i++){
            int updatedTight = (tight && (i == num[ind] -'0'));
            if(!started && (i == 0)){
                ans = (ans + solve(num, ind+1, updatedTight, 0, prev)) % MOD;
            }else if(!started || (abs(prev - i) == 1)){
                ans = (ans + solve(num, ind+1, updatedTight, 1, i)) % MOD;
            }
        }

        return dp[ind][tight][started][prev+1] = ans;


    }


    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        long long Right = solve(high, 0, 1, 0, -1);

        memset(dp, -1, sizeof(dp));
        long long Left = solve(low, 0,1,0,-1);

        long long dif = (Right - Left) % MOD;
        if(dif < 0){
            dif = (dif + MOD) % MOD;
        }

        
        int extra = 1;
        for(int i=1; i< low.size(); i++){
            if(abs(low[i] - low[i-1]) != 1){
                extra = 0;
                break;
            }
        }

        return (dif + extra) % MOD;
        
    }
};