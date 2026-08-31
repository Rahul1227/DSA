class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for(auto num : nums){
            xorResult ^= num;
        }
        int splitPos = -1;
        for(int i=0; i<32; i++){
            if(xorResult & (1 << i)){
                splitPos = i;
                break;
            }

        }

        vector<int> bucket1;
        vector<int> bucket2;
        for(auto num: nums){
            if(num &(1<<splitPos)){
                bucket1.push_back(num);
            }else{
                bucket2.push_back(num);
            }
        }

        vector<int> ans;
        int res1 = 0;
        for(auto num:bucket1){
            res1 ^= num;
        }
        ans.push_back(res1);
        res1 = 0;
        for(auto num: bucket2){
            res1 ^= num;
        }
        ans.push_back(res1);

        return ans;
        
    }
};