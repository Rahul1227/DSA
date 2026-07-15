class Solution {
public:
    // ind, tight, started
    int dp[11][2][2];

    int solve(string &num, vector<string>& digits, int ind, int tight, int started){
        // base case
        if(ind == num.size()){
            return 1;
        }

        if(dp[ind][tight][started] != -1) return dp[ind][tight][started];

        int limit = (tight ? num[ind] -'0' : 9);
        int ans = 0;

        for(auto str : digits){
            int digit = stoi(str);
            if(digit <= limit){
                int updatedTight = (tight && (digit == num[ind] -'0'));
                if(!started && digit == 0){
                     ans += solve(num, digits, ind+1, updatedTight, 0);
                }else{
                    if(digit !=0){
                        ans += solve(num, digits, ind+1, updatedTight, 1);
                    }
                }
               

            }
        }

        return dp[ind][tight][started] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<string> newDigits;
        newDigits.push_back("0");
        for(auto str: digits){
            newDigits.push_back(str);
        }
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(num, newDigits, 0,1,0) -1;
        
        
    }
};