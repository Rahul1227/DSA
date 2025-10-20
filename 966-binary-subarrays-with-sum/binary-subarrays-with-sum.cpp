class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int currSum = 0;
        int ans = 0;
        for(auto num : nums){
            currSum += num;
            int rem = currSum - goal;
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];

            }


            mp[currSum]++;
        }
        return ans;
        
    }
};