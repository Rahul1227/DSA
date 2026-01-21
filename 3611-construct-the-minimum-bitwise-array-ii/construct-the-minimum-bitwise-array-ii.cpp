class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i] == 2){
                ans.push_back(-1);
                continue;
            }
            bool found = false;
            for(int j =0; j<32; j++){
                if((nums[i] & (1 <<j))){
                    continue;
                }

                int prev = j-1;
                int x = nums[i] ^ (1 << prev);
                ans.push_back(x);
                found = true;
                break;


            }

            if(!found){
                ans.push_back(-1);
            }
        }

        return ans;
        
    }
};