class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int i =0;
        int j =0;
        int n = s.size();
        unordered_map<char, int> hashMap;

        while(j<n){
            if(hashMap.find(s[j]) == hashMap.end()){
                
                maxlen = max (maxlen, j-i+1);
                hashMap[s[j]] =  j;
                j++;
            }else{
                while(i < j && hashMap.find(s[j]) != hashMap.end()){
                    hashMap.erase(s[i]);
                    i++;
                }
            }
            
            

        }
        return maxlen;
            
        
        
    }
};