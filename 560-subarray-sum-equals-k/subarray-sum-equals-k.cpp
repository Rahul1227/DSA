class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // if(k == 0) return 0;
        int n = nums.size();
        int currSum = 0;
        int ans = 0;
        map<int,int> mp;
        mp[0] = 1;
        for(int i =0; i<n; i++){
            currSum += nums[i];
            int rem = currSum - k;
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[currSum]++;
               


            

        }
        return ans;
        
    }
};