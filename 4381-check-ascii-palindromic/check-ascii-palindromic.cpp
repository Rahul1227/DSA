class Solution {
private:
    string convertBinary(int num){
        string ans = "";
        while(num){
            int rem = num%2;
            num = num/2;
            char toInsert = rem + '0';
            ans.push_back(toInsert);

            
        }

        while(ans.size() < 8){
            ans.push_back('0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    bool isPalindrome(string &s){
        int i=0;
        int j = s.size()-1;

        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool isPalindromic(string s) {
        string finalStr = "";
        for(auto c  : s){
            int num = c;
            string temp = convertBinary(num);
            finalStr += temp;
        }

        for(auto c  : finalStr){
            cout<<c;
        }

        return isPalindrome(finalStr);
        
    }
};