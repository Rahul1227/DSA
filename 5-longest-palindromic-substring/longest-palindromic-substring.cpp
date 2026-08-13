class Solution {
private:
    int getLen(int i, int j, string &s){
        // int len = 1;
        int n = s.size();
        while(i>= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
public:
    string longestPalindrome(string s) {
        int startInd = 0;
        int maxLen = 1;
        int n = s.size();

        for(int i=0; i<n; i++){
            int oddLen = getLen(i,i,s);

            int evenLen = getLen(i,i+1, s);

            int currLen = max(oddLen, evenLen);

            if(currLen > maxLen){
                maxLen = currLen;
                startInd =i-((currLen-1)/2);
            }

        }

        // cout<<startInd<<"   "<<maxLen<<endl;

        return s.substr(startInd, maxLen);
        
    }
};