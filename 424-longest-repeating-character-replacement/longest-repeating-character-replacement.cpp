class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int maxLen = 0;
        int i =0;
        int j = 0;
        int n = s.size();
        int maxFreq = 0;
        while(j < n){
            char c = s[j];
            freq[c-'A']++;
            maxFreq = max(maxFreq, freq[c-'A']);

            if((j-i+1) <= maxFreq + k){
                maxLen = max(maxLen, j-i+1);
            }
            
            if((j-i+1) > maxFreq + k){
                freq[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return maxLen;
        
    }
};