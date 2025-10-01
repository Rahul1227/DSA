class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int k = n-1;
        for(int i =0; i<=k; i++){
            if(nums[i] == 0 && i != j){
                swap(nums[i], nums[j]);
                j++;
                i--;
            }

            if(nums[i] == 2 && i != k){
                swap(nums[i],nums[k]);
                k--;
                i--;
            }
        }
        
    }
};