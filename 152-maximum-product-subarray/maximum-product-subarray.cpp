class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int currProduct = 1;
        int currProduct2 = 1;
        for(int i=0; i<n; i++){
            currProduct *= nums[i];
            currProduct2 *= nums[n-i-1];
            ans = max({ans, currProduct, currProduct2});
            if(currProduct == 0){
                currProduct = 1;
            }
            if(currProduct2 == 0){
                currProduct2 = 1;
            }
        }

        return ans;
        
    }
};