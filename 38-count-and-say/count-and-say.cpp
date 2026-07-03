class Solution {
private:
    void solve(int n, string &ans){
        //base case
        if( n == 1){
            ans.push_back('1');
            return;
        }

        solve(n-1, ans);
        int i =0;
        int j = 0;
        int len = ans.size();
        string result ="";
        while(j < len){
            while(j < len && ans[i] == ans[j]){
                j++;
            }
            int length = j - i;
            string lenStr = to_string(length);
            for(auto c : lenStr){
               result.push_back(c);
            }
           result.push_back(ans[i]);
            i = j;
            

        }
        ans = result;
    }
public:
    string countAndSay(int n) {
        string ans = "";
        solve(n, ans);
        return ans;
        
    }
};