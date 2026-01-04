class Solution {
private:
    bool isPalindrome(int i, int j, string &s){
        while( i<= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }


    void solve(int ind, vector<string> &curr, vector<vector<string>> &ans, string &s){
        //base case
        if(ind > s.size()){
            return;
        }

        if(ind == s.size()){
            ans.push_back(curr);
            return;
        }

        
        string st="";
        for(int i = ind; i< s.size(); i++){
            st += s[i];
            if(isPalindrome(ind, i,s)){
                curr.push_back(st);
                solve(i+1, curr, ans ,s);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, curr, ans, s);
        return ans;
        
    }
};