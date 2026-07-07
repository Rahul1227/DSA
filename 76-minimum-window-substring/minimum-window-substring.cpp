class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n2 > n1) return "";
        int startingPoint = -1;
        int minLen = INT_MAX;
        unordered_map<char,int> mp;
        for(auto c : t){
            mp[c]++;
        }

        int count = n2;
        int i =0;
        int j = 0;

        while(j < n1){
            mp[s[j]]--;
            if(mp[s[j]] >= 0) count--;
            while(count == 0){
                int currLen = j - i +1;
                if(currLen < minLen){
                    minLen = currLen;
                    startingPoint = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
                i++;
            }




            j++;
        }

        if(startingPoint != -1){
            return s.substr(startingPoint, minLen);
        }else{
            return "";
        }

        
    }
};