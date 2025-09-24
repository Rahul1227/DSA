class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // brute force 
        // generating all the subarray and then checking
        int n = nums.size();
        int result =0;

        for(int i =0; i<n; i++){
            int sum =0;
            for(int j =i; j<n; j++){
                sum += nums[j];
                if(sum == k) result++;

            }
        }
        return result;
        
    }
};