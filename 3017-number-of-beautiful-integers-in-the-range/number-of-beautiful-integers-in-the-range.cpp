class Solution {
public:
    int offset = 10;
    //ind, tight, balance, mod
    int dp[12][2][22][22][2];

    int solve(string &num, int ind, int tight, int balance, int mod, int k, int started, int currNum){
        if(ind == num.size()){
            if((balance == offset) && (mod == 0)){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[ind][tight][balance][mod][started] != -1){
            return dp[ind][tight][balance][mod][started];
        }

        int limit = (tight ? num[ind] -'0' : 9);

        int ans = 0;
        for(int i=0; i<=limit; i++){
            int updatedTight = (tight & (i == num[ind] -'0'));
            int updatedNum = currNum * 10 + i;
            int updatedMod = updatedNum % k;

            if(!started && i == 0){
                ans += solve(num, ind+1, updatedTight, balance,updatedMod,k,0,0);
            }else if(i%2 ==0){
                ans += solve(num, ind+1, updatedTight, balance+1,updatedMod,k,1,updatedNum);
            }else{
                ans += solve(num, ind+1, updatedTight, balance-1,updatedMod,k,1,updatedNum);
            }
            
        }

        return dp[ind][tight][balance][mod][started] = ans;
    }


    int numberOfBeautifulIntegers(int low, int high, int k) {
        string num1 = to_string(high);
        memset(dp,-1, sizeof(dp));
        int Right = solve(num1, 0,1,offset,0,k, 0,0);

        string num2 = to_string(low-1);
        memset(dp, -1, sizeof(dp));
        int Left = solve(num2, 0,1,offset,0,k,0,0);

        int ans = Right - Left;
        return ans;
        
    }
};