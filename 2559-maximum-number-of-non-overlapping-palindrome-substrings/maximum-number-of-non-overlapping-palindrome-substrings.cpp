class Solution {
private:
    vector<vector<bool>> isPalindrome;

    int solve(int ind, vector<int>& dp, string& s, int k) {
        int n = s.size();

        if (ind == n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int ans = solve(ind + 1, dp, s, k);

        for (int i = ind; i < n; i++) {
            int len = i - ind + 1;

            if (len >= k && isPalindrome[ind][i]) {
                ans = max(ans, 1 + solve(i + 1, dp, s, k));
            }
        }

        return dp[ind] = ans;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1) return n;

        isPalindrome.assign(n, vector<bool>(n, false));

        // populating isPalindrome
        for(int len = 1; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                if(i ==  j){
                    isPalindrome[i][j] = true;
                }else if(i+1 == j){
                    isPalindrome[i][j] = s[i] == s[j];
                }else{
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);
                }
            }
        }

        vector<int> dp(n + 1, -1);

        return solve(0, dp, s, k);
    }
};