const int MOD = 1e9+7;
class Solution {
public:
    long long dp[201][201][201];

    // int getGCD (int a, int b){
    //     if(b == 0) return a;

    //     return getGCD(b, a%b);
    // }

    long long solve(int ind, int gcd1, int gcd2, vector<int> &nums){
        //base case
        if(ind == nums.size()){
            return (gcd1 == gcd2);
        }

        if(dp[ind][gcd1][gcd2] != -1) return dp[ind][gcd1][gcd2];

        // int updatedGCD1 = getGCD(gcd1, nums[ind]);
        // int updatedGCD2 = getGCD(gcd2, nums[ind]);
        long long take1 = solve(ind+1,__gcd(gcd1, nums[ind]), gcd2, nums);
        long long take2 = solve(ind+1, gcd1, __gcd(gcd2, nums[ind]), nums);
        long long skip = solve(ind+1, gcd1, gcd2, nums);

        return dp[ind][gcd1][gcd2] = (1LL*take1 + (take2 + skip) % MOD) % MOD;
    }


    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int gcd1 = 0;
        int gcd2 = 0;
        return solve(0,gcd1, gcd2, nums) - 1;

        
    }
};