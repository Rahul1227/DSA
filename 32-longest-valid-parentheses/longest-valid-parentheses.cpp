class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int n = s.size();
        if( n == 0) return maxLen;
        int left = 0;
        int right = 0;

        for(int i =0; i<n; i++){
            if(s[i] == '(') left++;
            else right++;

            if(left == right){
                int currLen = 2 * right;
                maxLen = max(maxLen, currLen);
            }

            if(right > left){
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') left++;
            else right++;

            if(left == right){
                int currLen = 2 * right;
                maxLen = max(maxLen, currLen);
            }

            if(left > right){
                left = 0;
                right = 0;
            }
        }

        return maxLen;
        
    }
};