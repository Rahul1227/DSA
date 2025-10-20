class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int currOdd;
        int ans  = 0;
        for(auto num : nums){
            if((num & 1)==1){
                currOdd ++;
            }
            int rem = currOdd - k;
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }

            mp[currOdd]++;
        }
        return ans;
        
    }
};