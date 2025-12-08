class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int ans = 0;
        int i = 0;
        int j = 1;
        while(j < n){
            if(nums[j] > nums[j-1]){
                j++;
            }else{
                ans = max(ans, j-i);
                cout<<ans;
                i = j;
                j++;
            }

        }
        ans = max(ans, j-i);
        return ans;
        
    }
};