class Solution {
private:    
    bool solve(string s1, string s2, map<string, bool> &mp){
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 == 1 && n2 == 1){
            return s1[0] == s2[0];
        }

        string key = s1 + '$' + s2;
        if(mp.count(key)){
            return mp[key];
        }

        for(int i=1; i<n1; i++){
            bool notSwapped = solve(s1.substr(0,i), s2.substr(0,i), mp) && 
                                solve(s1.substr(i,n1-1), s2.substr(i,n1-i), mp);
            bool swapped = solve(s1.substr(i,n1-i), s2.substr(0, n1-i), mp) && solve(s1.substr(0,i), s2.substr(n1-i, i), mp);

            bool result = notSwapped || swapped;
            if(result){
                return mp[key] = true;
            }
        }

        return mp[key] = false;

        
    }
public:
    bool isScramble(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        map<string, bool> dp;
        return solve(s1, s2, dp);
        
    }
};