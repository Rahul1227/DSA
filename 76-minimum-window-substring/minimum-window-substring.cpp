class Solution {
private:
    bool isValid(unordered_map<char,int> &needed, unordered_map<char,int> &present){
        for(auto [key, val] : needed){
            if(!present.count(key)) return false;
            else{
                if(val > present[key]) return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int startingInd = -1;
        unordered_map<char,int> needed;
        for(auto c : t){
            needed[c]++;
        }
        unordered_map<char,int> present;
        int i =0;
        int j =0;
        int n = s.size();
        int minLen =INT_MAX;
        // int currLen =0;
        while(j < n){
            present[s[j]]++;

            while(isValid(needed, present)){
                int currLen = j-i+1;
                if(currLen < minLen){
                    startingInd = i;
                    minLen = currLen;
                    // ans = s.substr(i, minLen);
                }
                present[s[i]]--;
                i++;
            }
            j++;
        }
        if(startingInd != -1){
            return s.substr(startingInd, minLen);
        }else{
            return "";
        }

        
    }
};