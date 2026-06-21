class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd =0;
        int maxEnd = 0;
        int jumps = 0;

        for(int i =0; i<nums.size(); i++){
            if(i > maxEnd) return -1;

            if(i > currEnd){
                jumps++;
                currEnd = maxEnd;
            }

            maxEnd = max(maxEnd, i + nums[i]);
        }
        return jumps;
    }
};