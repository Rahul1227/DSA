class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]= 1;
        int sum = 0;
        int result =0;
        int n = nums.size();

        for(int i =0; i<n; i++){
            sum += nums[i];
            int rem = sum - k;
            if(mp.find(rem) != mp.end()){
                result += mp[rem];


            }



            mp[sum]++; 
        }
        return result;
        
    }
};