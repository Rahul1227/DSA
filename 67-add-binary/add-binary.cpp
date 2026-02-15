class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int aLen = a.size();
        int bLen = b.size();
        int len = max(aLen, bLen);
        for(int i =0; i<len; i++){
            int firstChar = i<aLen ? a[i] - '0' : 0;
            int secondChar = i < bLen ? b[i] - '0' : 0;
            int sum = firstChar + secondChar + carry;
            if(sum == 3){
                ans.push_back('1');
                carry = 1;
            }else if(sum == 2){
                ans.push_back('0');
                carry = 1;
            }else if(sum == 1){
                ans.push_back('1');
                carry = 0;
            }else{
                ans.push_back('0');
                carry = 0;
            }
            
        }

        if(carry == 1){
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};