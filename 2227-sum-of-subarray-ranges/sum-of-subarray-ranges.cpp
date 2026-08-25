class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int currMax = nums[i];
            int currMin = nums[i];
            for(int j=i+1; j<n; j++){
                currMax = max(currMax, nums[j]);
                currMin = min(currMin, nums[j]);
                ans += 1LL * (currMax - currMin);
            }
        }

        return ans;
        
    }
};