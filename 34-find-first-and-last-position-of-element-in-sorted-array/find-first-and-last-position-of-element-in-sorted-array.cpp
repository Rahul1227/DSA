class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        bool isPresent = binary_search(nums.begin(), nums.end(), target);

        if(!isPresent){
            return {-1,-1};
        }else{
            auto it1 = lower_bound(nums.begin(), nums.end(), target);
            auto it2 = upper_bound(nums.begin(), nums.end(), target);
            int ind1 = it1 -nums.begin();
            int ind2 = it2 - nums.begin();
            ind2--;
            return {ind1, ind2};
        }
        
    }
};