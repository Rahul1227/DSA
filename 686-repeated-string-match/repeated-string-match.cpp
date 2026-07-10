class Solution {
private:
    vector<int> getLPS(string s){
        int n = s.size();
        vector<int> lps(n, 0);
        int len =0;
        int i =1;
        while(i < n){
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


    bool solve(string &a, string &b){
        vector<int> lps = getLPS(b);
        int i =0;
        int j =0;
        int n1 = a.size();
        int n2 = b.size();

        while(i<n1){
            if(a[i] == b[j]){
                i++;
                j++;
                if(j == n2) return true;
            }else if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }

        return false;

        

    }
public:
    int repeatedStringMatch(string a, string b) {
        string str = a;
        int ans = 1;
        while(str.size() < b.size()){
            str += a;
            ans++;
        }
        if(solve(str,b)) return ans;
        str += a;
        ans++;
        if(solve(str,b)) return ans;
        return -1;

        
    }
};