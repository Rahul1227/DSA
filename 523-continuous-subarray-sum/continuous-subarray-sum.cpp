class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] =  -1;
        // int i =0;
        int j =0;
        int n = nums.size();
        int currSum = 0;
        while(j<n){
            currSum += nums[j];
            int rem = currSum % k;
            if(mp.count(rem) && j - mp[rem] >=2){
                return true;
            }
            if(!mp.count(rem)){
                mp[rem] = j;
            }
            j++;
        }
        return false;
        
    }
};