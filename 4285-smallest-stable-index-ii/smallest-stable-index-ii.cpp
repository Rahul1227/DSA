class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maximums(n);
        vector<int> minimums(n);
        maximums[0] = nums[0];
        minimums[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            maximums[i] = max(maximums[i-1], nums[i]);
        }

        for(int i=n-2; i>=0; i--){
            minimums[i] = min(minimums[i+1], nums[i]);
        }

        for(int i=0; i<n; i++){
            if(maximums[i] - minimums[i] <=k){
                return i;
            }
        }

        return -1;
    }
};