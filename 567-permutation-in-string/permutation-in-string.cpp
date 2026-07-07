class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        unordered_map<char, int> mp;
        for(auto c : s1){
            mp[c]++;

        }

        int count = n1;
        int i =0;
        int j =0;
        while( j<n2){
            mp[s2[j]]--;
            if(mp[s2[j]] >= 0) count--;

            if(j-i+1 > n1){
                mp[s2[i]]++;
                if(mp[s2[i]] >0) count++;
                i++;
            }

            if(count == 0){
                return true;
            }



            j++;
        }

        return false;
        
    }
};