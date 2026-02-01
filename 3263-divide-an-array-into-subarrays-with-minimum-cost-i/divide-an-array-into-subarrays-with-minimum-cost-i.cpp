class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int i=1; i< nums.size(); i++){
            if(nums[i] < min2){
                min2 = nums[i];
            }
            if(min2 < min1){
               swap(min1, min2);
            }
        }
        // sort(nums.begin()+1, nums.end());
        return nums[0] + min1 + min2;
        
    }
};