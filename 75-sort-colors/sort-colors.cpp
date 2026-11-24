class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        for(int current=0; current<=right; current++){
            if(nums[current] == 0){
                swap(nums[left], nums[current]);
                left++;
            }else if(nums[current] == 2){
                swap(nums[right], nums[current]);
                right--;
                current--;
            }
        }
        
    }
};