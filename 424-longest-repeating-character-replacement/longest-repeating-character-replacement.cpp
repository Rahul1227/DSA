class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int hashMap[26];
        int l =0;
        int r =0;
        int maxf =0;
        int maxlen =0;
        while(r<n){
            hashMap[s[r] - 'A']++;
            maxf = max(maxf, hashMap[s[r]-'A']);

            if((r-l+1) - maxf > k){
                hashMap[s[l] - 'A']--;
                l++;
            }

            if((r-l+1) - maxf <=k){
                maxlen = max(maxlen, (r-l+1));
            }
            r++;
        }

        return maxlen;

        
    }
};