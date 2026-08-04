class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int minElement = nums[0];
        int maxElement = nums[0];

        for(auto num : nums){
            mp[num] = 1;
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
        }

        int currNum = minElement;
        while(currNum < maxElement){
            if(!mp.count(currNum)){
                ans.push_back(currNum);
            }
            currNum++;
        }

        return ans;

        
        
    }
};