class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minimums(n);
        minimums[n-1] = nums[n-1];
        

        for(int i=n-2; i>=0; i--){
            minimums[i] = min(minimums[i+1], nums[i]);
        }
        int currMaxi = 0;
        for(int i=0; i<n; i++){
            currMaxi = max(currMaxi, nums[i]);
            if(currMaxi - minimums[i] <=k){
                return i;
            }
        }

        return -1;
    }
};