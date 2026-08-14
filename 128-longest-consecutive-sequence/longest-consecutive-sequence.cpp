class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto num : nums){
            mp.insert(num);
        }

        int ans = 0;
        for(auto &num : mp){
            if(mp.count(num-1)){
                continue;
            }else{
                int currNum = num;
                while(mp.count(currNum)){
                    ans = max(ans, currNum - num +1);
                    currNum++;
                }
            }
        }
        return ans;
        
    }
};