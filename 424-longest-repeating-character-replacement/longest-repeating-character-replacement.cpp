class Solution {
private:
    int maxPerChar(string &s, int k, char c){
        int n = s.size();
        int currMaxLen =0;
        int i =0;
        int j =0;

        while(j<n){
            char letter = s[j];
            if(letter != c && k>0){
                k--;
            }else if(letter != c && k==0){
                while(s[i] == c){
                    i++;
                }
                i++;
            }


            currMaxLen = max(currMaxLen, j-i+1);
            j++;
        }
        return currMaxLen;
    }
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for(char c = 'A'; c<= 'Z'; c++){
            int currLen = maxPerChar(s,k,c);
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};