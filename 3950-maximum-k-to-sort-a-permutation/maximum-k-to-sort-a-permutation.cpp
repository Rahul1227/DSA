class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k  = -1;
        
        int n = nums.size();

        for(int i=0; i<n;i++){
            if(i != nums[i]){
                k = k & nums[i];
            }
        
        
        }

        if(k == -1){
            return 0;
        }
        return k;
        
    }
};