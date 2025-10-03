class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int aheadLesser = -1;
        for(int i = n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                aheadLesser = i-1;
                break;
            }
            
        }

        if(aheadLesser != -1){
            int swapWith = aheadLesser;
            for(int i = n-1; i>=aheadLesser; i--){
                if(nums[i] > nums[swapWith]){
                    swapWith = i;
                    break;
                }
            }

            swap(nums[aheadLesser], nums[swapWith]);

        }
        
        reverse(nums.begin()+ aheadLesser +1, nums.end());



        
    }
};