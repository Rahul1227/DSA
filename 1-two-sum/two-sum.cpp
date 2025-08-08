class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();\
        vector<int> result;
        for(int i =0; i<n; i++){
            int left = target - nums[i];
            if(mp.find(left) != mp.end()){
                result.push_back(mp[left]);
                result.push_back(i);
                break;

            }
            mp[nums[i]] = i;
        }
        return result;
    }
};