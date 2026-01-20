class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i =0; i<n; i++){
            int target = nums[i];
            bool found = false;
            for(int j =1; j< target; j++){
                if((j | j+1) == target){
                    found = true;
                    ans.push_back(j);
                    break;
                }
            }

            if(!found){
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};