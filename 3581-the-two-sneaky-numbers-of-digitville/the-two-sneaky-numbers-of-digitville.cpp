class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> hashMap(n,0);
        for(auto num : nums){
            hashMap[num]++;
        }
        vector<int> ans;
        for(int i =0; i< hashMap.size(); i++){
            if(hashMap[i] == 2){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};