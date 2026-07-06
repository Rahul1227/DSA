class Solution {
private:
    vector<int> getLPS(string &s){
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i =1;
        while(i<n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else if(len != 0){
                len = lps[len-1];
            }else{
                i++;
            }
        }
        return lps;
    }
public:
    string shortestPalindrome(string s) {
        string original = s;
        reverse(s.begin(), s.end());
        string str = original + '$' + s;
        vector<int> lps = getLPS(str);
        int n = str.size();
        string result = s.substr(0, original.size() - lps[n -1]);
        return result + original;
        
        
    }
};