class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currReach = 0;
        int maxReach = 0;
        for(int i =0; i<nums.size(); i++){
            if(i > maxReach) return false;
            maxReach = max(maxReach,i+ nums[i]);
        }
        return true;
    }
};