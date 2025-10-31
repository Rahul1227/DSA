class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        int xorResult = 0;
        // with the elements
        for(auto num: nums){
            xorResult = xorResult ^ num;
        }

        // with the indices
        for(int i =0; i<n; i++){
            xorResult = xorResult ^ i;
        }

        // now the xorResult contains the xored value of the ans;

        int setBit = xorResult & -xorResult;
        cout<<setBit;

        int group0 = 0; // for the 0
        int group1 = 0; // for the 1

        for(auto num : nums){
            int bit = (num & setBit);
            cout<<bit;
            if(bit){
                group1 = group1 ^ num;
            }else{
                group0 = group0 ^ num;
            }
        }

        // for indices also
        for(int i =0; i<n; i++){
            int bit = i & setBit;
            if(bit){
                group1 = group1 ^ i;
            }else{
                group0 = group0 ^ i;
            }
        }

        return {group0, group1};
        
    }
};