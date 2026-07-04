class Solution {
private:
    vector<int> getLPS(string &s){
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1;
        int len = 0;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    i++;
                }
            }
        }
        return lps;

    }
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps = getLPS(s);
        return s.substr(0, lps[n-1]);
        
    }
};