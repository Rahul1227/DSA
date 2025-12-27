class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;

        //  calculating the frequence
        for(int i =0; i< nums.size(); i++){
            mp[nums[i]]++;
        }

        // populating the priority queue
        for (auto [key, val] : mp){
            pq.push({val,key});

        }

        vector<int> ans;

        while(k--){
            auto  [count, key] = pq.top();
            pq.pop();
            ans.push_back(key);

        }

        return ans;


        
    }
};