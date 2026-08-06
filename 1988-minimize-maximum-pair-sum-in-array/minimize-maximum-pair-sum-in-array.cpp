class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxSum = 0;
        int i =0;
        int j = n-1;
        while(i<j){
            int currSum = nums[i] + nums[j];
            maxSum = max(currSum, maxSum);
            i++;
            j--;
        }
        return maxSum;
        
    }
};