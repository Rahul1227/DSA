class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i =0; i<n-2; i++){
            // remove duplicate
            if(i > 0 && nums[i-1] == nums[i]) continue;

            int j = i +1;
            int k = n-1;
            while(j< k){
                int currSum  = nums[i] + nums[j] + nums[k];
                if(currSum > 0){
                    k--;
                }else if(currSum < 0){
                    j++;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k &&  nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
        
    }
};