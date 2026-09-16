class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int maxReach = 0;
        for(int i=0; i<nums.size(); i++){
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach == n-1) return true;
            if(i >= maxReach) return false;
        }
        return true;
    }
};