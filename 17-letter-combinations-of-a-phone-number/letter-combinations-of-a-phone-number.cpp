class Solution {
private:
    void solve(int ind, string &curr, vector<string> &ans, vector<string> &given){
        if(ind == given.size()){
            ans.push_back(curr);
            return;
        }
        int len = given[ind].size();
        for(int i =0; i< len; i++){
            curr.push_back(given[ind][i]);
            solve(ind+1,curr,ans, given);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // doing the mapping
        unordered_map<int, string> mp;
        char c = 'a';
        for(int i = 2; i<=9; i++){
            int count = 3;
            while(count--){
                mp[i].push_back(c);
                c++;
            }
            if(i == 7 || i == 9){
                mp[i].push_back(c);
                c++;
            }
            
        }

        vector<string> ans;
        vector<string> given;
        for(auto c : digits){
            given.push_back(mp[c-'0']);
        }
        string curr ="";
        

        solve(0,curr,ans, given);
        return ans;


        

        
    }
};