class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        int n = s1.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);

        for(int i =1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    int skip1 = prev[j];
                    int skip2 = curr[j-1];
                    curr[j] = max(skip1, skip2);
                }
            }
            prev =  curr;
        }

        return prev[n];
        
    }
};