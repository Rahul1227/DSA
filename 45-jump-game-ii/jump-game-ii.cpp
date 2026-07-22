class Solution {
public:
    int jump(vector<int>& nums) {
        int count =0;
        int currReach = 0;
        int maxReach = 0;
        for(int i =0; i< nums.size(); i++){
            if(i > maxReach) return -1;
            if(i > currReach){
                count++;
                currReach = maxReach;
            }
            maxReach = max(maxReach, i + nums[i]);
        }

        return count;
    }
};