class Solution {
private:
    int getMatch(string &s){
        int n = s.size();
        vector<int> lps(n, 0);
        int i =1;
        int len = 0;
        while(i<n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else if(len !=  0){
                len = lps[len-1];
            }else{
                i++;
            }
        }
        for(auto num: lps){
            cout<<num<<" ";
        }
        return lps[n-1];
    }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string newStr = s + '$' + rev;
        int matching = getMatch(newStr);
        // cout<<matching<<endl;

        string firstHalf = rev.substr(0, n-matching);
        return firstHalf + s;
        
    }
};