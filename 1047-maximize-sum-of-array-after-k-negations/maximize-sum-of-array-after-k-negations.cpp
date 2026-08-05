class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i =0;
        int n = nums.size();
        while(i<n && k){
            if(nums[i] < 0){
                nums[i] = - nums[i];
                i++;
                k--;
            }else{
                if(k%2 != 0){
                    if(i> 0 && nums[i-1] < nums[i]){
                        nums[i-1] = -nums[i-1];
                    }else{
                        nums[i] = -nums[i];
                    }
                    
                }
                k = 0;
            }
        }

        if(k > 0){
            if(k % 2 != 0){
                nums[n-1] = -nums[n-1];
            }
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return totalSum;
        
    }
};