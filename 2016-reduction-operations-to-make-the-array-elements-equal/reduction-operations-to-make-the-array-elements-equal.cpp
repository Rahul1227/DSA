class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int, greater<>>mp;
        for(auto num: nums){
            mp[num]++;
        }
        int ans = 0;

        while(mp.size() > 1){
            auto it1 = mp.begin();
            int freq1 = it1->second;
            ans += freq1;
            mp.erase(it1);

            auto it2 = mp.begin();
            it2->second += freq1;
        }

        return ans;
        
    }
};