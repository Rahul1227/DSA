class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        for(auto &flower : flowers){
            int start = flower[0];
            int end = flower[1]+1;
            mp[start]++;
            mp[end]--;
        }

        map<int,int> indToCurrSum;
        indToCurrSum[0] = 0;
        int currSum = 0;
        for(auto &[key, val] : mp){
            currSum += val;
            indToCurrSum[key] = currSum;
        }

        vector<int> time;
        vector<int> value;

        for(auto &[key,val]: indToCurrSum){
            time.push_back(key);
            value.push_back(val);
        }

        vector<int> ans;
        for(auto currPerson : people){
            auto it = upper_bound(time.begin(), time.end(), currPerson);
            if(it == time.end()){
                ans.push_back(0);
            }else{
                int ind = it - time.begin();
                ans.push_back(value[ind-1]);
            }
        }

        return ans;
        
    }
};