class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        for(auto [key, val] : mp){
            if(val == n/2) return key;
        }
        return -1;
        
    }
};