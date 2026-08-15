class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorRes = 0;
        bool allZero = true;
        for(auto num : nums){
            xorRes ^= num;
            if(num != 0){
                allZero = false;
            }
        }

        if(xorRes == 0){
            if(allZero) return 0;
            else return n-1;
        }else{
            return n;
        }
        
    }
};