class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int posInd = 0;
        int negInd = 1;
        
        for(int i =0; i<n; i++){
            if(nums[i] >=0){
                result[posInd] = nums[i];
                posInd = posInd + 2;
            }else{
                result[negInd] = nums[i];
                negInd = negInd + 2;
            }
        }

        return result;
        
    }
};