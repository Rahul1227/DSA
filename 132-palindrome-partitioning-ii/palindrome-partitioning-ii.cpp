class Solution {
private:
    bool isPalindrome(string &s){
        int left =0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }




    int solve(int ind, string &s, vector<int> &dp){
        if(ind == s.size()){
            return 0;
        }

        if(dp[ind] != -1) return dp[ind];

        string st ="";
        int ans = INT_MAX;
        for(int i =ind; i<s.size(); i++){
            st += s[i];
            if(isPalindrome(st)){
                int curr = 1 + solve(i+1, s,dp);
                ans = min(ans, curr);

            }
           
        }
        return dp[ind] = ans;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp)-1;

        
    }
};