class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &dp, string &s1, string &s2){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, dp, s1, s2);
        } else {
            return dp[i][j] = 0;  // ✓ Fixed: substring breaks
        }
    }
    
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());  // ✓ Fixed: reverse the string
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxLen = 1;
        int start = 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int currLen = solve(i, j, dp, s, s2);
                
                if(currLen > maxLen){
                    // ✓ Fixed: validate it's a real palindrome
                    int startInOriginal = i - currLen + 1;
                    int startInReversed = n - 1 - j;
                    
                    if(startInOriginal == startInReversed){
                        maxLen = currLen;
                        start = startInOriginal;  // ✓ Fixed: correct start index
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};