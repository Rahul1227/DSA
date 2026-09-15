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

        isPalindrome.assign(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] &&
                    (len <= 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, -1);

        return solve(0, dp, s, k);
    }
};