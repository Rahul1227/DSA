class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minEle = INT_MAX;
        int i = 0;
        int j = n-1;
        while(i<=j){
            int mid =(i+j)/2;

            if(nums[i] <= nums[mid]){
                minEle = min(minEle, nums[i]);
                i = mid + 1;
            }else{
                minEle = min(minEle, nums[mid]);
                j = mid-1;

            }
        }

        return minEle;
        
    }
};