class Solution {
private:
    bool isAnagram(string &s1, string &s2){
        int len1 = s1.size();
        int len2 = s2.size();

        if(len1 != len2){
            return false;
        }

        vector<int> hashMap(26,0);
        for(int i =0; i<len1; i++){
            hashMap[s1[i] - 'a']++;
            hashMap[s2[i] - 'a']--;
        }

        for(int i =0; i<26; i++){
            if(hashMap[i] != 0){
                return false;
            }
        }

        return true;

    
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        int n = words.size();
        for(int i = 1; i<n; i++){
            if(!isAnagram(words[i-1], words[i])){
                ans.push_back(words[i]);
            }
        }

        return ans;
        
    }
};