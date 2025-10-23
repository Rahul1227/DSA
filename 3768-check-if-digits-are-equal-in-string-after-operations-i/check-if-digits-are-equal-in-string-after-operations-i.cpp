class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while(n > 2){
            for(int i =0; i<n-1; i++){
                int a = s[i] - '0';
                int b = s[i+1] - '0';
                int sum = a + b;
                int rem = sum % 10;
                // char toInsert = '0' + rem;
                // cout<<toInsert<<endl;
                s[i] = rem;
            }
            n--;
        }


        return s[0] == s[1];
    }
};