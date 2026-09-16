class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxReach = 0;
        int currReach = 0;

        for(int i=0; i<n; i++){
            // if(i > maxReach)
            if(i > currReach){
                count++;
                currReach = maxReach;
            }
            maxReach = max(maxReach, i + nums[i]);
        }

        return count;
        
    }
};