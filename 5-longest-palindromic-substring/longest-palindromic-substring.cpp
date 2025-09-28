class Solution {
private:
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &dp){

        if(dp[i][j] != -1) return dp[i][j];

        while(i<j){
            if(s[i] == s[j]){
                i++; 
                j--;
            }else{
                dp[i][j] = false;
                break;
            }
        }
        if(i >= j) dp[i][j] = true;
        return dp[i][j];
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // if(n == 1) return true;
        vector<vector<int>> dp(n+1, vector<int>(n,-1));
        int maxlen =0;
        int startPoint = -1;

        for(int i =0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isPalindrome(i,j,s,dp)){
                    int currLen = j-i+1;
                    if(currLen > maxlen){
                        maxlen = currLen;
                        startPoint = i;
                    }
                }
            }
        }
        
        return s.substr(startPoint, maxlen);
        
    }
};