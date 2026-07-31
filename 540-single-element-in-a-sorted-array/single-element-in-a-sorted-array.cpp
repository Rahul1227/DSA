class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int l =0;
        int r = n-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(mid-1 >=0 && nums[mid] != nums[mid-1] && mid+1 < n && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if(mid % 2==0){
                if(nums[mid] == nums[mid+1]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }

            }else{
                if(nums[mid] != nums[mid+1]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }

            }
        }

        return nums[l];
        
    }
};