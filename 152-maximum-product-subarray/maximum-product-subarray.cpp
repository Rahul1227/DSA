class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxAns = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        int n = nums.size();
        for(int i =0; i<n; i++){
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];

            maxAns = max({maxAns, prefix, suffix});

            if(prefix == 0){
                prefix = 1;
            }

            if(suffix == 0){
                suffix = 1;
            }
        }

        return maxAns;
        
    }
};