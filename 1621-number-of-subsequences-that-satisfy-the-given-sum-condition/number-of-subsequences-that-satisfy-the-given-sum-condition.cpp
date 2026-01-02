class Solution {
    const int MOD = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pow2(n+1, 1);
        for(int i = 1; i <= n; i++){
            pow2[i] = (pow2[i-1] * 2LL) % MOD;
        }

        long long count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] + nums[i] > target) break;

            int maxVal = target - nums[i];
            int ansInd = upper_bound(nums.begin()+i, nums.end(), maxVal)
                         - nums.begin() - 1;

            if(ansInd >= i){
                count = (count + pow2[ansInd - i]) % MOD;
            }
        }
        return count;
    }
};


