class Solution {
private:
    long long T(int num, int k, bool mul){
        if(mul){
            return 1LL * num * k;
        }else{
            return num/k;
        }
    }

    long long solve(vector<int> &nums, int k, bool mul){
        int n = nums.size();
        vector<long long> nT(n), cT(n), eT(n);
        nT[0] = nums[0];
        cT[0] = T(nums[0],k, mul);
        eT[0] = LLONG_MIN/8;

        for(int i=1; i<n; i++){
            long long trans = T(nums[i],k, mul);
            nT[i] = max(1LL *nT[i-1] + nums[i], (long long)nums[i]);
            cT[i] = max({
                        nT[i-1] +trans,
                        cT[i-1] + trans,
                        trans
                    });
            eT[i] = max(eT[i-1] + nums[i], cT[i-1] + nums[i]);

        }

        long long ans = LLONG_MIN;
        for(int i=0; i<n; i++){
            ans = max({ans, cT[i], eT[i]});
        }
        return ans;

    }
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums, k, true), solve(nums, k, false));
        
    }
};