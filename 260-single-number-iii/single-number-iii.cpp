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

        int res1 = 0;
        int res2 = 0;
        for(auto num: nums){
            if(num &(1<<splitPos)){
                res1 ^= num;
            }else{
                res2 ^= num;
            }
        }

        return {res1, res2};
        
    }
};