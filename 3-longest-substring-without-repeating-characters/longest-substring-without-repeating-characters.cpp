class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> seen;
        int maxLen = 0;
        int j =0;
        int i =0;
        while(j < n){
            char c = s[j];
            if(seen[c] > 0){
                while(seen[c] > 0){
                    seen[s[i]]--;
                    i++;
                }
            }
            maxLen = max(maxLen, j-i+1);
            seen[c]++;
            j++;
            
        }
        return maxLen;
        
    }
};