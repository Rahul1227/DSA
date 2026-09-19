class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int count = 0;
        for(auto &[key, val] : mp){
            if(val.size() != 3) continue;
            int diff = val[1] - val[0];
            bool isValid = true;
            for(int i=2; i<val.size(); i++){
                int currDiff = val[i] - val[i-1];
                if(diff != currDiff){
                    isValid = false;
                    break;
                }
            }

            if(isValid) count++;
        }

        return count;
        
    }
};