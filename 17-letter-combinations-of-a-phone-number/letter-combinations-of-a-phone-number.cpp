class Solution {
private:
    void solve(int ind, string &curr, vector<string> &ans, unordered_map<int, string> &mp, string &digits){
        if(ind == digits.size()){
            cout<<"curr"<<curr<<endl;
            ans.push_back(curr);
            return;
        }

        string val = mp[digits[ind]-'0'];
        for(auto c: val){
            curr.push_back(c);
            solve(ind+1, curr, ans, mp, digits);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        char c = 'a';
        for(int i =2; i<=9; i++){
            int count = 3;
            while(count--){
                mp[i].push_back(c);
                c++;
            }

            if(i ==7 || i == 9){
                mp[i].push_back(c);
                c++;
            }

        }
        vector<string> ans;
        string curr ="";
        solve(0,curr,ans, mp, digits);
        return ans;
    }
};