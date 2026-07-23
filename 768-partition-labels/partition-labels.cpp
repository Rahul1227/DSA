class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        for(auto c : s){
            freq[c-'a']++;
        }
        vector<int> ans;
        int i = 0;
        int n = s.size();

        while(i < n){
            unordered_map<int,int> mp;
            int len = 0;
            do{
                int ind = s[i] -'a';
                if(!mp.count(ind)){
                    mp[ind] = freq[ind];
                }
                mp[ind]--;
                if(mp[ind] == 0){
                    mp.erase(ind);
                }
                len++;
                i++;
                

            }while(i<n && !mp.empty());
            ans.push_back(len);
            // i++;
        }
        return ans;
        
    }
};