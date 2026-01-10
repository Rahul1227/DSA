class Solution {
private:
    int expandAroundCenter(int left, int right, string &s){

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;

        
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 1;
        int start =0;
        for(int i =0; i < n; i++){
            int len1 = expandAroundCenter(i,i,s);
            int len2 = expandAroundCenter(i,i+1,s);
            int currLen = max(len1, len2);
            if(currLen > maxLen){
                maxLen = currLen;
                start = i - (currLen-1)/2;
            }
        }

        return s.substr(start, maxLen);
        
    }
};