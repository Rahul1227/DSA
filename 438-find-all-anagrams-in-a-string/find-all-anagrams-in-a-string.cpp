class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(m > n) return ans;
        unordered_map<char, int> mp;
        for(auto c : p){
            mp[c]++;
        }
        int count = m;
        int i =0;
        int j =0;

        while(j < n){
            mp[s[j]]--;
            if(mp[s[j]] >=0) count--;

            if(j-i+1 > m){
                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
                i++;
            }

            if(count == 0){
                ans.push_back(i);

            }
            j++;

        }

        return ans;
    }
};