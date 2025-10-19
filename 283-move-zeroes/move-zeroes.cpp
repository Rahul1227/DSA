class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // if(n<=1) return;
        int i =0;
        int j =0;
        int zeroCounter = 0;
        while(j<n){
            if(nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
            if(nums[j] == 0){
                zeroCounter++;
            }
            j++;
        }

        while(zeroCounter--){
            nums[i++] = 0;
        }
        
    }
};