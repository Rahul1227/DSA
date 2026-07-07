class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        vector<int> ans;
        int n1 = s.size();
        int n2 = p.size();
        if(n2 > n1) return ans;
        for(auto c: p){
            mp[c]++;
        }
        int count = n2;
        int i = 0;
        int j =0;
        while(j < n1){
            mp[s[j]]--;
            if(mp[s[j]] >=0) count--;

            if(j-i+1 > n2){
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