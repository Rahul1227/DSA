class Solution {
private:
    void solve(int n, string &ans){
        if(n == 1){
            ans = "1";
            return;
        }
        solve(n-1, ans);
        string curr ="";
        int i =0;
        int j =0;
        int len = ans.size();
        while(j < len || i<len){
            while(j < len && ans[i] == ans[j]){
                j++;
            }
            int currLen = j-i;
            string str = to_string(currLen);
            curr += str;
            curr += ans[i];
            i = j;
            j++;
        }
        ans = curr;
    }
public:
    string countAndSay(int n) {
        string ans ="";
        solve(n, ans);
        return ans;
        
    }
};