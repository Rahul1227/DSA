class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int prefixSum =0;
        mp[0] = -1;
        int n = nums.size();
        int maxlen = 0;

        for(int i =0; i<n; i++){
            prefixSum += nums[i] == 1 ? 1: -1;
            
            if(mp.count(prefixSum)){
                int len = i - mp[prefixSum];
                maxlen = max(maxlen, len);
            }else{
                mp[prefixSum] = i;
            }
        }

        return maxlen;
        
    }
};