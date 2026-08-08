class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j =0;
        int maxLen = 0;
        int zeroCount =0;

        while(j < n){
            if(nums[j] == 0){
                zeroCount++;
            }

            while(zeroCount > 1){
                if(nums[i]==0){
                    zeroCount--;
                }
                i++;
            }

            int currLen = j-i+1 - zeroCount;
            maxLen = max(maxLen, currLen);
            j++;
            
        }

        if(zeroCount){
            return maxLen;
        }else{
            return maxLen -1;
        }
        
        
    }
};