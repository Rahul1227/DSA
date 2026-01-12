class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mp[26]={0};
        for(char c: sentence){
            mp[c-'a']++;
        }

        for (auto val :  mp){
            if(val == 0) return false;
        }

        return true;
    }
};