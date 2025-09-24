class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        int result =0;
        int sum =0;
        hashMap[0] = 1;
        for(auto num: nums){
            sum += num;
            int rem = sum - k;
            if(hashMap.find(rem) != hashMap.end()){
                result += hashMap[rem];
            }
            hashMap[sum]++;


        }
        return result;
        
    }
};