class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        bool canChange = true;
        int i = 0;
        int j = 0;
        int maxSize = 0;
        while(j<n){
            if(nums[j] == 0){
                if(canChange){
                    canChange = false;
                }else{
                    maxSize = max(maxSize, j-i);
                    while(nums[i] != 0){
                        i++;
                    }
                    i++;


                }
            }
            j++;
        }
        maxSize = max(maxSize, j-i);
        return maxSize-1;
        
    }
};