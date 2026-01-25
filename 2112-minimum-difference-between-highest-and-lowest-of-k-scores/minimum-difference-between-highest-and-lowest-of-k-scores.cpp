class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i =0;
        int j = k-1;
        int diff = INT_MAX;
        while(j<n){
            int currDiff = nums[j]  - nums[i];
            diff = min(diff, currDiff);
            j++;
            i++;

        }

        return diff;

        
    }
};