class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        if(len1 != len2 || len1 == 0 || len2 == 0){
            return false;
        }

        vector<int> hashMap(26);
        for(int i =0; i<len1; i++){
            hashMap[s[i] - 'a']++;
            hashMap[t[i] - 'a']--;
        }

        // for(int i =0; i<len2; i++){
        //     hashMap[t[i] - 'a']--;
        // }

        // checking
        for(int i =0; i<26; i++){
            if(hashMap[i] != 0){
                return false;
            }
        }
        return true;
        
    }
};