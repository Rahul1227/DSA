class Solution {
private:
    bool isAlphaNumeric(char c){
        if((c>='a' && c<='z') || (c >='A' && c<='Z') || (c >='0' && c<='9'))return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i =0;
        int j = n-1;
        while(i<j){
            if(!isAlphaNumeric(s[i])){
                i++;
                continue;
            }

            if(!isAlphaNumeric(s[j])){
                j--;
                continue;
            }

            if(s[i] >='A' && s[i] <='Z'){
                s[i] ^= 32;
            }

            if(s[j] >= 'A' && s[j] <='Z'){
                s[j] ^= 32;
            }
            // cout<<s[i]<<"   "<<s[j]<<endl;
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;

        
    }
};