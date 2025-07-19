class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i <  n; i++){
            mp[nums[i]] = i;
        }

        int m = operations.size();
        for(int i =0 ; i<m ; i++){
            int ind = mp[operations[i][0]];
            nums[ind] = operations[i][1];
            mp[operations[i][1]] = ind;
        }

        return nums;
        
    }
};