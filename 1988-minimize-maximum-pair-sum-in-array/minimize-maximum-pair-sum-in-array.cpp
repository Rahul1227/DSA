class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minSum = nums[0] + nums[n-1];
        int i =1;
        int j = n-2;
        while(i<j){
            int currSum = nums[i] + nums[j];
            minSum = max(minSum, currSum);
            i++;
            j--;
        }

        return minSum;
    }
};