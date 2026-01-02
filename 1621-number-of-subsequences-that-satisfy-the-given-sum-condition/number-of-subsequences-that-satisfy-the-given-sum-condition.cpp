class Solution {
    const int MOD = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> power(n+1,1);
        for(int i =1; i<=n; i++){
            power[i] = (power[i-1]* 2LL) % MOD;
        }

        int count = 0;
        for(int i =0; i<n; i++){
            if(nums[i] + nums[i] > target) break;
            int toSearch = target - nums[i];
            auto it = upper_bound(nums.begin() + i, nums.end(), toSearch);
            int ind = (it - nums.begin()) - 1;
            if(ind >= i){
                count = (count + power[ind-i]) % MOD;
            }
            
        }

        return count;

        
    }
};