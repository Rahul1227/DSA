class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorResult = 0;
        for(auto num: nums){
            xorResult = xorResult ^ num;
        }
        return xorResult;
        
    }
};