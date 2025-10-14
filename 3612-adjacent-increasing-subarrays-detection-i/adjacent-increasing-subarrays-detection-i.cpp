class Solution {
private:
    bool isIncreasing(int i, int j, vector<int> &nums){
        if(i==j) return true;
        for(int k = i+1; k<=j; k++){
            if(nums[k] <= nums[k-1]){
                return false;
            }

        }

        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i =0; i<=(n-2*k); i++){
            if(isIncreasing(i,i+k-1,nums) && isIncreasing(i+k, i+2*k-1,nums)){
                return true;
            }
        }
        return false;


        
    }
};