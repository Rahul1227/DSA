class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force 
        // generating all the subarray and then checking
        // int n = nums.size();
        // int result =0;

        // for(int i =0; i<n; i++){
        //     int sum =0;
        //     for(int j =i; j<n; j++){
        //         sum += nums[j];
        //         if(sum == k) result++;

        //     }
        // }
        // return result;



        // optimal way
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