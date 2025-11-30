class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;

        int currSum = 0;
        int ans = 0;
        for(int i =0; i< nums.size(); i++){
            currSum += nums[i];
            int rem = currSum % k;
            if(rem < 0){
                rem = rem + k;
            }
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
                mp[rem]++;
            }else{
                mp[rem] = 1;
            }
        }

        return ans;
        
        
    }
};