class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int cumSum =0;
        long long validSubarray = 0;
        for(int i =0; i<n; i++){
            if(nums[i] == target){
                validSubarray += mp[cumSum];
                cumSum++;
            }else{
                cumSum--;
                validSubarray -= mp[cumSum];
            }
            ans += validSubarray;
            mp[cumSum]++;
        }
        return ans;
        
    }
};