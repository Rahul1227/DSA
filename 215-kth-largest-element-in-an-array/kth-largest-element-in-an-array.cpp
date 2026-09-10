class Solution {
private:

    int partition(vector<int> &nums, int low, int high){
        int pivotEle = nums[high];
        int i = low;
        for(int j=low; j<high; j++){
            if(nums[j] > pivotEle){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }

    int quickSelect(vector<int> &nums, int low, int high, int k){
        if(low <= high){
            int pivot = partition(nums, low, high);
            if(pivot == k-1){
                return nums[pivot];
            }else if(pivot > k-1){
                return quickSelect(nums, low, pivot-1, k);
            }else{
                return quickSelect(nums, pivot+1, high, k);
            }
        }
        return 0;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums,0, n-1, k);
        
    }
};