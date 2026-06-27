class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen =0;
        int i =0;
        int j =0;
        int n = nums.size();

        while(j < n){
            int digit = nums[j];

            if(digit != 1 && k > 0){
                k--;
            }else if(digit != 1 && k == 0){
                while(nums[i] != 0){
                    i++;
                }
                i++;

            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
        
    }
};