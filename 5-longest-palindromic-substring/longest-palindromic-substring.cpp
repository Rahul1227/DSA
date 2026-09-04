class Solution {
private:
    int getLen(int i, int j, string &s){
        int n = s.size();
        while(i>=0 && j<n){
            if(s[i] == s[j]){
                i--;
                j++;
            }else{
                return j-i-1;
            }
        }

        return j-i-1;
    }
public:
    string longestPalindrome(string s) {
        int startPoint = -1;
        int maxLen = 0;
        for(int i =0; i<s.size(); i++){
            int currLen = max(getLen(i,i,s), getLen(i,i+1,s));
            if(currLen > maxLen){
                maxLen = currLen;
                startPoint = (i - (maxLen-1)/2);
            }
        }
        
        return s.substr(startPoint, maxLen);
    }
};